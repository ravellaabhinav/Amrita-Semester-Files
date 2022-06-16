; Shift Left one bit

		TTL shiftleft.s
		AREA Program, CODE, READONLY
		ENTRY

 Main
		LDR 	R1, Value ; Load the value to be shifted
		MOV 	R1, R1, LSL #0x1 ; Shift Left one bit
		STR 	R1, Result ; Store the result
		SWI 	&11 ; exit

Value 	DCD &4242 ; Value to be shifted
Result 	DCD 0 ; Space to store result

		END
