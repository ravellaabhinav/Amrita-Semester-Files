		AREA prog1,CODE,READONLY

		ENTRY
		mov	r0,#0x11
		mov r1,r0, LSL#1
		mov r2,r1, LSL#1
stop	B stop
		END