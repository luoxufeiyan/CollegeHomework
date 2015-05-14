area example,code ,readonly		;循环实现1-10的累加
 entry
 code32
start
 mov r0,#10
 mov r1,#1
 mov r2,#0
loop
 add r2,r2,r1
 add r1,r1,#1
 sub r0,r0,#1
 cmp r0,#0
 bne loop
 end
