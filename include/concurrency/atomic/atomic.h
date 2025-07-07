#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct { volatile int counter; } atomic_t;

void atomic_store(atomic_t* obj, int value);
int atomic_load(const atomic_t* obj);
int atomic_exchange(atomic_t* obj, int value);
int atomic_compare_exchange(atomic_t* obj, int expected, int desired);
int atomic_fetch_add(atomic_t* obj, int arg);
int atomic_fetch_sub(atomic_t* obj, int arg);

#ifdef __cplusplus
}
#endif
