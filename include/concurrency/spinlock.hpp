#pragma once
#include "atomic/atomic.hpp"

namespace concurrency {

class spinlock {
    atomic lock_;
public:
    spinlock() noexcept;
    void lock() noexcept;
    bool try_lock() noexcept;
    void unlock() noexcept;
    
    spinlock(const spinlock&) = delete;
    spinlock& operator=(const spinlock&) = delete;
};

} // namespace concurrency
