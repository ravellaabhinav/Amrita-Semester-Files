		AREA    add64, CODE, READONLY
ENTRY
MAIN
        LDR    R0, =A        
        LDR    R1, [R0]            
        LDR    R2, [R0, #4]        
        LDR    R0, =Bs        
        LDR    R3, [R0]            
        LDR    R4, [R0, #4]        
      
        SUB    R6, R2, R4        
        SBC    R5, R1, R3       
      
        LDR    R0, =Result        
      
        STR    R5, [R0]            
        STR    R6, [R0, #4]        
      
        SWI    &11
      
A    DCD    &122AE640, &2F100123
Bs    DCD    &001019BF, &40023F51
Result    DCD    0
      
        END
			
			