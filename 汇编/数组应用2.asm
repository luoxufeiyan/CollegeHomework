area match, code, readonly 
       entry
start  ldr r1, =src
       add r5, r1, #len
       ldr r2, =dst
       add r6, r2, #length
       ldr r7, =array

inner  ldr r3, [r1]
       ldr r4, [r2]
       cmp r3, r4
       BEQ output
       add r2, r2, #4
       cmp r2, r6
       BLE inner
outer  add r1, r1, #4
       ldr r2, =dst
       cmp r1, r5
       BLE inner
       B stop

output str r3, [r7]
       add r7, r7, #4
       B outer

Stop    MOV r0,#0x18
    LDR r1,=0x20026
    SWI 0x123456
