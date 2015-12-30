HECBEX:
    MOV A,AL
    SUB A,1
    MOV AL,A
    MOV A,BL
    SBC A,0H
    MOV BL,A
    SNZ C
    JMP DONE
    MOV A,1
    ADD A,AH
DONE:
    RET

