   MOV r0, #0x61      ;x= #0x61 
   MOV r1, #0x12      ;y= #0x12 
   MOV r2, #0xA        ;
   SUB r3, r0,r1
   CMP r2, r3
   MOVGT r0,#0x0    ;(x-y)<3
   MOVLE  r1,#0x0
