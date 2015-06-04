area search, code, readonly 
       entry
start  mov r5, #num
       ldr r1, =src
       add r6, r1, #length
       ldr r3, =dst
       mov r4, #0

loop   ldr r2, [r1]
       cmp r2, r5
       BEQ output
inner  add r4, r4, #1
       add r1, r1, #4
       cmp r1, r6
       BLE loop
       B stop

output str r4, [r3]
       add r3, r3, #4
       B inner

Stop    MOV r0,#0x18
    LDR r1,=0x20026
    SWI 0x123456

end
