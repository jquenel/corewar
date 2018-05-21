.name "tortank"
.comment "tortank utilise hydrocanon. C'est super efficace"

recup:
	zjmp %:heart
start:
	ld %42991616, r12
	sti r12, %:recup, %-7
	ld %12, r12
	sti r12, %:recup, %-4
	sti r1, %:heart, %1
	ld %0, r12
	ld %0, r12
	ld %0, r12
	ld %0, r12
	ld %0, r12
	ld %0, r12
	ld %0, r12
	ld %0, r12
	ld %0, r12
	ld %0, r12
	ld %0, r12
	ld %-7, r10
	ld %1, r11
reload:
	live %420
	add r10, r11, r10
	zjmp %:carapace
	fork %:canon
	ld %0, r12
	zjmp %:reload


canon:
	ld %-64, r4
	ld %8, r7
	live %420
	fork %:yellow_ranger

	red_ranger:
		ld %67764155, r2						#0409ffe7
		ld %4, r3
		ldi %:jump1, %-1, r5
		add r5, r7, r5
		sti r5, %:jump1, %-1
		and r5, %65535, r5
		or r5, %4294901760, r5
		add r5, r3, r5
		sti r2, r5, %:jump1
		ld %0, r12
	jump1: zjmp %:recup

	yellow_ranger:
		ld %190054915, r2						#0b540203
		ldi %:jump2, %-1, r5
		add r5, r7, r5
		sti r5, %:jump2, %-1
		and r5, %65535, r5
		or r5, %4294901760, r5
		or r5, %4294901760, r5
		sti r2, r5, %:jump2
		ld %0, r3
	jump2: zjmp %:recup

heart:
	live %420
	ld %0, r1
	zjmp %:heart

carapace:
	live %420
	ld %167770880, r13
	ld %150995721, r14
	st r14, -100
	st r14, -102
	st r14, -104
	st r14, -106
	st r14, -108
	st r14, -110
	st r14, -112
	st r14, -114
	st r14, -116
	st r14, -118
	st r14, -120
	st r14, -122
	st r14, -124
	st r14, -126
	st r14, -128
	st r14, -130
	st r14, -132
	st r14, -134
	st r14, -136
	st r14, -138
	st r14, -140
	live %420
	st r13, 100
	st r13, 99
	st r13, 98
	st r13, 97
	st r13, 96
	st r13, 95
	st r13, 94
	st r13, 93
	st r13, 92
	st r13, 91
	st r13, 90
	st r13, 89
	st r13, 88
	st r13, 87
	st r13, 86
	ld %0, r12
	zjmp %:carapace
