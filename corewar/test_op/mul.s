.name "bonuses"
.comment "multiply, divide, not, shout"

ld %2, r2
ld %4, r3
mul r2, r3, r4
div r4, r3, r5
not r6, r7
live %1
ld %72, r8
vic r8
ld %101, r8
vic r8
ld %121, r8
vic r8
