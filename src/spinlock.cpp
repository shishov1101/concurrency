#include <concurrency/spinlock.hpp>
#include <concurrency/atomic/hint.hpp>

namespace concurrency {

spinlock::spinlock() noexcept : lock_(0) {}

void spinlock::lock() noexcept {
    while (lock_.exchange(1) == 1) {
        cpu_pause();
    }
}

bool spinlock::try_lock() noexcept {
    int expected = 0;
    return lock_.compare_exchange_strong(expected, 1);
}

void spinlock::unlock() noexcept {
    lock_.store(0);
}

} // namespace concurrency
