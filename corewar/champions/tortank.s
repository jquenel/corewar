.name "tortank"
.comment "tortank utilise hydrocanon. C'est super efficace"

recup:
	zjmp %:heart
start:
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
reload:
	live %420
	fork %:canon
	ld %0, r12
	zjmp %:reload


canon:
	ld %-64, r4
	ld %8, r7
	ld %-6, r10
	ld %1, r11
	live %420
	fork %:yellow_ranger

	red_ranger:
	live %420
		ld %67764155, r2						#0409ffe7
		ld %4, r3
		ldi %:jump1, %-1, r5
		add r5, r7, r5
		sti r5, %:jump1, %-1
		and r5, %65535, r5
		or r5, %4294901760, r5
		add r5, r3, r5
		sti r2, r5, %:jump1

		add r10, r11, r10
		zjmp %:heart
		ld %0, r12
	jump1: zjmp %:recup

	yellow_ranger:
	live %420
		ld %190054915, r2						#0b540203
		ldi %:jump2, %-1, r5
		add r5, r7, r5
		sti r5, %:jump2, %-1
		and r5, %65535, r5
		or r5, %4294901760, r5
		or r5, %4294901760, r5
		sti r2, r5, %:jump2

		add r10, r11, r10
		zjmp %:heart
		ld %0, r3
	jump2: zjmp %:recup

heart:
	live %420
	zjmp %:heart
