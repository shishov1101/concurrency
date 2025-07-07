#if defined(__aarch64__)

.text
.align 4

.global _atomic_store
_atomic_store:
    str w1, [x0]
    ret

.global _atomic_load
_atomic_load:
    ldr w0, [x0]
    ret

.global _atomic_exchange
_atomic_exchange:
    mov x2, x0
1:
    ldxr w0, [x2]
    stlxr w3, w1, [x2]
    cbnz w3, 1b
    ret

.global _atomic_compare_exchange
_atomic_compare_exchange:
    mov x3, x0
1:
    ldxr w0, [x3]
    cmp w0, w1
    b.ne 2f
    stlxr w4, w2, [x3]
    cbnz w4, 1b
2:
    ret

.global _atomic_fetch_add
_atomic_fetch_add:
    mov x2, x0
1:
    ldxr w0, [x2]
    add w3, w0, w1
    stlxr w4, w3, [x2]
    cbnz w4, 1b
    ret

.global _atomic_fetch_sub
_atomic_fetch_sub:
    mov x2, x0
1:
    ldxr w0, [x2]
    sub w3, w0, w1
    stlxr w4, w3, [x2]
    cbnz w4, 1b
    ret

#endif
