		MOV R1,#0 ; R1 is i
		MOV R0,#0 ; R0 is sum
loop: 	ADD R0,R0,R1 ; sum = sum + i
		ADD R1,R1,#1 ; i++
		CMP R1,#10 ; i <= 10
		BLE loop
halt: 	B halt
		end