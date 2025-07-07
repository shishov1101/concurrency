#pragma once
#include "atomic.h"

namespace concurrency {

class atomic {
    atomic_t atom_;
public:
    atomic() noexcept { atomic_store(&atom_, 0); }
    explicit atomic(int value) noexcept { atomic_store(&atom_, value); }
    
    void store(int value) noexcept { atomic_store(&atom_, value); }
    int load() const noexcept { return atomic_load(&atom_); }
    int exchange(int value) noexcept { return atomic_exchange(&atom_, value); }
    
    bool compare_exchange_strong(int& expected, int desired) noexcept {
        int old = atomic_compare_exchange(&atom_, expected, desired);
        if (old != expected) {
            expected = old;
            return false;
        }
        return true;
    }
    
    int fetch_add(int arg) noexcept { return atomic_fetch_add(&atom_, arg); }
    int fetch_sub(int arg) noexcept { return atomic_fetch_sub(&atom_, arg); }
    
    operator int() const noexcept { return load(); }
    atomic& operator=(int value) noexcept { store(value); return *this; }
    int operator++() noexcept { return fetch_add(1) + 1; }
    int operator--() noexcept { return fetch_sub(1) - 1; }
};

} // namespace concurrency
