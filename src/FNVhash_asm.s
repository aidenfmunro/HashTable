global FNVHash_asm

FNVHash_asm:
        movsx   rax, BYTE [rdi]
        test    rsi, rsi
        je      .end
        add     rsi, rdi
.loop:
        mov     rdx, rax
        lea     r8, [rax + rax * 8]
        mov     rcx, rax
        add     rdi, 1
        sal     rdx, 7
        sal     rcx, 24
        lea     rdx, [rdx + r8 * 2]
        add     rdx, rax
        sal     rax, 8
        add     rdx, rax
        movsx   rax, BYTE [rdi - 1]
        add     rcx, rdx
        xor     rax, rcx
        cmp     rsi, rdi

        jne     .loop
.end:
        ret