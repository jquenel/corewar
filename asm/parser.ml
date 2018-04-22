module List =
  struct
    include List

    let rec union l = function
      | [] -> l
      | hd :: tl when mem hd l -> union l tl
      | hd :: tl -> union (hd :: l) tl

    let replace_assoc key value list =
      (key, value) :: remove_assoc key list
  end

open List

type non_terminal =
  [ `S
  | `ExpectComment
  | `ExpectName
  | `Comment
  | `Name
  | `Label
  | `Instruction
  | `OperandNext
  | `Operand
  | `Val ]

let all_non_terminals : non_terminal list =
  [ `S
  ; `ExpectComment
  ; `ExpectName
  ; `Comment
  ; `Name
  ; `Label
  ; `Instruction
  ; `OperandNext
  ; `Operand
  ; `Val ]

type terminal =
  [ `LineSeparator
  | `CommentCommand
  | `NameCommand
  | `StringLiteral
  | `LabelString
  | `Operator
  | `SeparatorChar
  | `DirectChar
  | `Register
  | `LabelVal
  | `Number ]

let all_terminals : terminal list =
  [ `LineSeparator
  ; `CommentCommand
  ; `NameCommand
  ; `StringLiteral
  ; `LabelString
  ; `Operator
  ; `SeparatorChar
  ; `DirectChar
  ; `Register
  ; `LabelVal
  ; `Number ]

type symbol = [ non_terminal | terminal ]

type symbol_narrow =
  | NonTerminal of non_terminal
  | Terminal of terminal

let narrow_symbol_type : symbol -> _ = function
  | `S
  | `ExpectComment
  | `ExpectName
  | `Comment
  | `Name
  | `Label
  | `Instruction
  | `OperandNext
  | `Operand
  | `Val as s
    -> NonTerminal s
  | `LineSeparator
  | `CommentCommand
  | `NameCommand
  | `StringLiteral
  | `LabelString
  | `Operator
  | `SeparatorChar
  | `DirectChar
  | `Register
  | `LabelVal
  | `Number as s
    -> Terminal s

let rules : (non_terminal * symbol list) list = [
    `S, [`LineSeparator; `S];
    `S, [`Name; `LineSeparator; `ExpectComment];
    `S, [`Comment; `LineSeparator; `ExpectName];
    `ExpectComment, [`LineSeparator; `ExpectComment];
    `ExpectComment, [`Comment; `LineSeparator; `Label];
    `ExpectName, [`LineSeparator; `ExpectName];
    `ExpectName, [`Name; `LineSeparator; `Label];
    `Comment, [`CommentCommand; `StringLiteral];
    `Name, [`NameCommand; `StringLiteral];
    `Label, [`LabelString; `Instruction];
    `Label, [`Instruction];
    `Label, [];
    `Instruction, [`Operator; `Operand; `OperandNext; `LineSeparator; `Label];
    `Instruction, [`LineSeparator; `Label];
    `OperandNext, [`SeparatorChar; `Operand; `OperandNext];
    `OperandNext, [];
    `Operand, [`DirectChar; `Val];
    `Operand, [`Val];
    `Operand, [`Register];
    `Val, [`LabelVal];
    `Val, [`Number]
  ]

let rec compute_add_set first_sets w =
  let rec aux acc = function
    | [] -> union acc [`Epsilon]
    | hd :: tl ->
       match narrow_symbol_type hd with
       | Terminal hd -> union acc [(hd :> [ terminal | `Epsilon ])]
       | NonTerminal hd when mem `Epsilon (assoc hd first_sets) ->
          let add_set = filter ((<>) `Epsilon) (assoc hd first_sets) in
          aux (union acc add_set) tl
       | NonTerminal hd -> union acc (assoc hd first_sets)
  in
  aux [] w

let compute_first_sets rules =
  let rec aux first_sets = function
    | [] -> first_sets
    | (nt, w) :: tl ->
       let first_set = assoc nt first_sets in
       let add_set = compute_add_set first_sets w in
       let new_first_set = union first_set add_set in
       if new_first_set == first_set
       then aux first_sets tl
       else aux (replace_assoc nt new_first_set first_sets) tl
  in
  let rec loop acc =
    let new_acc = aux acc rules in
    if acc != new_acc then loop new_acc else acc
  in
  loop (rev_map (fun s -> s, []) all_non_terminals)

let compute_follow_sets first_sets rules =
  let rec aux follow_sets nt = function
    | [] -> follow_sets
    | hd :: tl ->
       match narrow_symbol_type hd with
       | Terminal _ -> aux follow_sets nt tl
       | NonTerminal hd ->
          let follow_set = assoc hd follow_sets in
          let add_set = compute_add_set first_sets tl in
          let new_follow_set = match partition ((=) `Epsilon) add_set with
            | [], _ -> union follow_set add_set
            | _, add_set ->
               union follow_set (union add_set (assoc nt follow_sets))
          in
          if new_follow_set == follow_set
          then aux follow_sets nt tl
          else aux (replace_assoc hd new_follow_set follow_sets) nt tl
  in
  let rec loop acc =
    let new_acc = fold_left (fun acc (rnt, w) -> aux acc rnt w) acc rules in
    if acc != new_acc then loop new_acc else acc
  in
  loop (rev_map (function `S -> `S, [`Epsilon] | s -> s, []) all_non_terminals)

let _ =
  let first_sets = compute_first_sets rules in
  let follow_sets = compute_follow_sets first_sets rules in
  let parse_table =
    Array.make_matrix (length all_non_terminals) (length all_terminals + 1) (-1)
  in
  let push_rule i j k = match parse_table.(i).(j) with
    | -1 -> parse_table.(i).(j) <- k
    | k' when k' = k -> ()
    | _ -> failwith "rule conflict"
  in
  iteri (fun i nt ->
      iteri (fun j t ->
          iteri (fun k -> function
              | nt', _ when nt <> nt' -> ()
              | _, [] when mem t (assoc nt follow_sets) -> push_rule i j k
              | _, [] -> ()
              | _, hd :: _ ->
                 match narrow_symbol_type hd with
                 | Terminal hd when (hd :> [terminal | `Epsilon]) = t
                   -> push_rule i j k
                 | NonTerminal hd when mem t (assoc hd first_sets) || mem `Epsilon (assoc hd first_sets) && mem t (assoc nt follow_sets)
                   -> push_rule i j k
                 | _ -> ()
            ) rules
        ) (all_terminals :> [terminal | `Epsilon] list)
    ) all_non_terminals;
  iteri (fun i nt ->
      let j = length all_terminals in
      iteri (fun k -> function
          | nt', _ when nt <> nt' -> ()
          | _, [] when mem `Epsilon (assoc nt follow_sets) -> push_rule i j k
          | _, [] -> ()
          | _, hd :: _ ->
             match narrow_symbol_type hd with
             | NonTerminal hd when mem `Epsilon (assoc hd first_sets) && mem `Epsilon (assoc nt follow_sets)
               -> push_rule i j k
             | _ -> ()
        ) rules
    ) all_non_terminals;
  parse_table
