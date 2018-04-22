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
  let open List in
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
  let open List in
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

let first_sets = compute_first_sets rules
