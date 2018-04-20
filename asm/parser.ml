module List =
  struct
    include List

    let rec union l = function
      | [] -> l
      | hd :: tl when mem hd l -> union l tl
      | hd :: tl -> union (hd :: l) tl

    let replace_assoc key new_value list =
      (key, new_value) :: remove_assoc key list
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

let compute_first_sets rules =
  let open List in
  let rec aux first_sets = function
    | [] -> first_sets
    | (nt, []) :: tl ->
       let first = assoc nt first_sets in
       if mem `Epsilon first
       then aux first_sets tl
       else aux (replace_assoc nt (`Epsilon :: first) first_sets) tl
    | (nt, whd :: wtl) :: tl ->
       let first = assoc nt first_sets in
       match narrow_symbol_type whd with
       | Terminal hd ->
          let hd = (hd :> [ terminal | `Epsilon ]) in
          if mem hd first
          then aux first_sets tl
          else aux (replace_assoc nt (hd :: first) first_sets) tl
       | NonTerminal hd when mem `Epsilon (assoc hd first_sets) ->
          let new_first =
            union
              first
              (union
                 (filter ((<>) `Epsilon) (assoc hd first_sets))
                 (assoc nt (aux first_sets [nt, wtl])))
          in
          if new_first == first
          then aux first_sets tl
          else aux (replace_assoc nt new_first first_sets) tl
       | NonTerminal hd ->
          let new_first = union first (assoc hd first_sets) in
          if new_first == first
          then aux first_sets tl
          else aux (replace_assoc nt new_first first_sets) tl
  in
  let rec loop acc =
    let acc_next = aux acc rules in
    if acc != acc_next then loop acc_next else acc
  in
  split rules |> fst |> union [] |> rev_map (fun s -> s, []) |> loop

let first_sets = compute_first_sets rules
