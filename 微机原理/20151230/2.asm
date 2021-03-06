    N=40
DATAS SEGMENT
DATABUF DW N
    DB N DUP(?)
DIVISORS DW 10000,1000,100,10,1
RESULTS  DB 0,0,0,0,0
DATAS ENDS

STACKS SEGMENT STACK 'STACK'
    DW 100H DUP()
TOP LABEL WORD
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
    MOV AX,STACKS
    MOV SS,AX
    LEA SP,TOP
    ;GENERATE RANDOM DATA
    MOV CX,DATABUF
    LEA SI,DATABUF+2
    MOV BL,23
    MOV AL,11
LP: 
    MOV [SI],AL
    INC SI
    ADD AL,BL
    CMP AL,100
    JBE NOMIN
    SUB AL,100
NOMIN:    
    LOOP LP
    ;ASS DATA
    MOV CX,DATABUF
    DEC CX
    LEA SI,DATABUF+2
    ADD SI,CX
LP1:
    PUSH CX
    PUSH SI
LP2:
    MOV AL,[SI]
    CMP AL,[SI-1]
    JBE NOXCHG
    XCHG AL,[SI-1]
    MOV [SI],AL
NOXCHG:
    DEC SI
    LOOP LP2
    POP SI
    POP CX
    LOOP LP1
    ;DISPLAY ALL DATA
    MOV CX,10
    LEA SI,DATABUF+2
LP3:
    MOV AL,[SI]
    CMP AL,80
    JBE LESS80
    CALL DISPAL
    MOV AL,20H
    MOV AH,02
    MOV DL,AL
    INT 21H
    INC SI
LESS80:
    LOOP LP3
    ;此处输入代码段代码
    MOV AH,4CH
    INT 21H
    ;DISP AL
DISPAL PROC NEAR
    PUSH AX
    PUSH CX
    PUSH DX
    PUSH AX
    MOV SI,OFFSET DIVISORS
    MOV DI,OFFSET RESULTS
    MOV CX,5
AA:
    MOV DX,0
    DIV WORD PTR[SI]
    ADD AL,48; PLUS 48 TOBE ASCII CODE
    MOV BYTE PTR [DI],AL
    INC DI
    ADD SI,2
    MOV AX,DX
    LOOP AA
    MOV CX,4
    MOV DI,OFFSET RESULTS
BB:
    CMP BYTE PTR [DI],'0';DON'T PRINT FORWARD 0
    JNE PRINT
    INC DI
    LOOP BB
PRINT:
    MOV DX,DI
    MOV AH,9
    INT 21H
    MOV AX,4C00H
    INT 21H
    POP DX
    POP CX
    POP AX
    RET 
DISPAL ENDP
    ;COVERT HEX INTO 10
CHANG PROC NEAR
    CMP AL,10
    JNGE CHANG1
    ADD AL,7
CHANG1:
    ADD AL,30H
    RET
CHANG ENDP
CODES ENDS
    END START

