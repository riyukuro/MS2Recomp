; ms2::hook::Register for the full-exe links: every game obj carries MS2_REPLACE registration statics (built for the
; hook DLL) that call it at static init. The closed link takes shim_runtime.obj's no-op; asm.py puts this one in
; <OUT>/asm/hookglue.lib, so the prelink and the alias link resolve it too, and an obj that defines it wins (a lib
; member is only pulled for a symbol still unresolved, no duplicate). Returns false: nothing is hooked in the exe.
_TEXT SEGMENT
?Register@hook@ms2@@YA_NPEAUReplacement@12@@Z PROC
    xor eax, eax
    ret
?Register@hook@ms2@@YA_NPEAUReplacement@12@@Z ENDP
_TEXT ENDS
END
