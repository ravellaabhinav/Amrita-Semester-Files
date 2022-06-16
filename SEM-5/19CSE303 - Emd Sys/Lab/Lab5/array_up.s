;Array example by AKS
;There is an  array of 32 bit constants
;array[6] = 1,2,3,4,5,6
;run this code and observe r3, r2 and r1
;traversing the array starting from the beginning array[0]. array[1], array[2]...array[5]
		AREA array_traverse_up, CODE, READONLY  ;traversing the array starting from the beginning array[0]. array[1], array[2]...array[5]
		ENTRY
		adr r2, array    ;get the base adress of the array in r2, ie, adress of the first element in the array
		mov r1, #0		 ;r1 serves as the index into the array range of values: 0 to 5
loop	cmp r1,#6		 ;we are done if r1>=6
		bge done		 ;done
		ldr r3, [r2, r1,LSL #2]		;load the array element to r3, this requires computing the adress of each elemnt
		adds r1, r1 ,#1				;increment the index by one
		b loop						;repeat as long as r1<=5
done	b	done					;terminate in forever loop
		align						;required for aligning the words at correct boundaries in memory
array 	dcd 1,2,3,4,5,6				;declaration of the array of words with 6 element
		end