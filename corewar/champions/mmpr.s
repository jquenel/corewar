.name "Mighty Morphin Power Rangers"
.comment "mighty_morphin_intro.mp3"

recup:
	zjmp %:team2
start:
	sti r1, %:pink_ranger, %1
	fork %:team2
	live %420

laser_attack:
	ld %-64, r4
	fork %:yellow_ranger

	red_ranger:
		ld %67764155, r2						#0409ffe7
		ld %4, r3
		sti r2, %:start, %4
		ld %0, r5
		zjmp %:start

	yellow_ranger:
		ld %190054915, r2						#0b540203
		sti r2, %:start, %0
		ld %0, r3
		zjmp %:start

team2:
	pink_ranger:
		live %420
		zjmp %:pink_ranger
	fork %:megazord
	ld %0, r12
	zjmp %:pink_ranger

megazord:
	ld %1, r12
	fork %:legs

	arms:
		live %420
		ld %0, r12
		ld %0, r12
		fork %:right_arm

		left_arm:
		live %420
			st r1, r2
			ld %251883523,r3					#0f037003
			ld %0, r12
			ld %0, r12
			live %420
			zjmp %:gogo_power_ranger

		right_arm:
		live %420
			ld %4294902016, r2					#ffff0100
			ld %436432899, r3					#1a037003
			ld %0, r12
			live %420
			zjmp %:gogo_power_ranger
	
	legs:
		live %420
		fork %:right_leg
		
		left_leg:
			ld %251883523, r2					#0f037003
			ld %386101251, r3					#17037003
			ld %0, r12
			ld %0, r12
			live %420
			zjmp %:gogo_power_ranger

		right_leg:
			ld %57672192, r2					#03700200
			ld %318992387, r3					#13037003
			ld %0, r12
			live %420
			zjmp %:gogo_power_ranger
	
gogo_power_ranger:
		st r2, 15
		st r3, -1
		live %420
