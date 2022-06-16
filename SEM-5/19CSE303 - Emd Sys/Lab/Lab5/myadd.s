		AREA myadd, CODE, READONLY
		ENTRY 
		mov r0, #1
		mov r1, #2
		add r2, r0, r1
		add r1,r1,#1
		swi &11
		end