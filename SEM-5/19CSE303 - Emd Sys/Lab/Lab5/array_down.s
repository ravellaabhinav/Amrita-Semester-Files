;Array example by AKS
;There is an  array of 32 bit constants
;array[6] = 1,2,3.4.5.6
;run this code and observe r3, r2 and r1
;traversing the array starting from the end array[5]. array[4], array[3]...array[0]
		AREA array_traverse_down, CODE, READONLY
		ENTRY
		mov r1, #5
		adr r2, array 
loop	ldr r3, [r2, r1,LSL #2]
		subs r1, r1 ,#1
		bge loop
done	b	done
		align
array 	dcd 1,2,3,4,5,6
		end
