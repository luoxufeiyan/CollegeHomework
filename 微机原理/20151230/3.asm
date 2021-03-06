DATAS SEGMENT
N=80
DATABUF DW N
		DB N DUP(?);此处输入数据段代码 
DATAS ENDS

STACKS SEGMENT
DW 100H DUP(?)
TOP LABEL WORD    ;此处输入堆栈段代码
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
    MOV CX,DATABUF
    LEA SI,DATABUF+2
    MOV BL,11
    MOV AL,42
LP:
	MOV [SI],AL
	INC SI
	ADD AL,BL
	CMP AL,100
	JBE LO
	SUB AL,100
LO:	LOOP LP
	
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
	MOV CX,10
	LEA SI,DATABUF+2
LP3:
	MOV AL,[SI]
	CMP AL,80
	JB LO2
	CALL DISPAL
	MOV AL,20H
	MOV AH,02
	MOV DL,AL
	INT 21H
	INC SI
LO2:
	LOOP LP3
LP4:
	MOV AL,[SI]
	DEC SI
	MOV BL,[SI]
	CMP AL,BL
	JNE LP5
	CALL DISPAL
	MOV AL,20H
	MOV AH,02
	MOV DL,AL
	INT 21H 
	INC SI
	INC SI
	JMP LP4;10个数以后如果后面和第十个有相等就输出
		   ;此处输入代码段代码
LP5:
    MOV AH,4CH
    INT 21H
DISPAL PROC NEAR
	   PUSH AX
	   PUSH CX
	   PUSH DX
	   CALL TRANS16TO10
	   MOV AH,02
	   MOV DL,AL
	   INT 21H
	   POP DX
	   POP CX
	   POP AX
	   RET
DISPAL ENDP
TRANS16TO10 PROC NEAR
	  CMP AL,100
	  JE CHANG100
	  SUB AL,80
	  CMP AL,10
	  JNGE CHANG80
	  SUB AL,10
	  CMP AL,10
	  JNGE CHANG90	  
CHANG80:
	  MOV BL,AL
	  MOV AL,8
	  ADD AL,30H
	  MOV AH,02
	  MOV DL,AL
	  INT 21H
	  MOV AL,BL
	  ADD AL,30H
	  JMP CHANG
CHANG90:
	  MOV BL,AL
	  MOV AL,9
	  ADD AL,30H
	  MOV AH,02
	  MOV DL,AL
	  INT 21H
	  MOV AL,BL
	  ADD AL,30H
	  JMP CHANG  
CHANG100:
	  MOV AL,1
	  ADD AL,30H
	  MOV AH,02
	  MOV DL,AL
	  INT 21H
	  MOV AL,0
	  ADD AL,30H
	  MOV AH,02
	  MOV DL,AL
	  INT 21H
	  MOV AL,0
	  ADD AL,30H
CHANG:
	  RET
TRANS16TO10 ENDP
CODES ENDS
    END START
