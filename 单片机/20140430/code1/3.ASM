              MOV R5,#3
LOOP1:   MOV P2,#0
              ACALL DELAY
              MOV P2,#0FFH
              ACALL DELAY
              DJNZ R5,LOOP1
LOOP2:  MOV P2,P1
	 SJMP LOOP2

DELAY:   MOV R0,#100
DEL0:     MOV R1,#50
DEL1:     MOV R2,#25
DEL2:     DJNZ R2,DEL2
             DJNZ R1,DEL1
             DJNZ R0,DEL0
             RET
             END
