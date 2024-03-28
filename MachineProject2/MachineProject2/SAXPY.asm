section .data
section .text
bits 64
default rel
global saxpy_asm
saxpy_asm:
    push   rsi 					; non-volatile register
    push   rbp
    mov    rbp, rsp
    add    rbp, 16
    add    rbp, 8               ; +8 for 1 additional push
    mov    rsi, [rbp + 32] 		; rsi = n
    movss  xmm1, xmm0           ; copy A to xmm1

saxpy_loop:
    cmp     rsi, 0
    je      saxpy_exit

    mulss   xmm0, [rdx]             ; xmm0 = A * X[i]
    addss   xmm0, [r8]              ; xmm0 = A * X[i] + Y[i]
    movss   [r9], xmm0              ; Z[i] = A * X[i] + Y[i]

    add     rdx, 4                  ; increment X pointer
    add     r8, 4                   ; increment Y pointer
    add     r9, 4                   ; increment Z pointer
    dec     rsi                     ; decrement loop counter
    movss   xmm0, xmm1              ; restore A
    jmp     saxpy_loop              ; loop until n elements processed

saxpy_exit:
    pop    rbp
    pop    rsi
    ret