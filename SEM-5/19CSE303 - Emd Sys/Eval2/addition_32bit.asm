	AREA ADDITION32bit, CODE, READONLY ;
	ENTRY
START
	MOV R7, #0x40000000
	LDR R1, [R7]
	ADD R7, R7, #4
	LDR R2, [R7]
	ADD R4, R1, R2
	MOV R7, #0X4000001C
	STR R4, [R7]
STOP B STOP
	END