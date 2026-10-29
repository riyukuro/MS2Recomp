; Minimal stand-ins for the WDK prologue macros the CryptoPP 5.6.2 x64 asm uses.
alloc_stack MACRO n
    sub rsp, n
    .allocstack n
ENDM
push_reg MACRO r
    push r
    .pushreg r
ENDM
rex_push_reg MACRO r
    db 48h
    push r
    .pushreg r
ENDM
save_xmm128 MACRO r, off
    movdqa [rsp + off], r
    .savexmm128 r, off
ENDM
