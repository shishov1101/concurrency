#pragma once

namespace concurrency {

inline void cpu_pause() noexcept {
#if defined(__aarch64__)
    __asm__ __volatile__("yield" ::: "memory");
#else
    __asm__ __volatile__("" ::: "memory");
#endif
}

inline void compiler_barrier() noexcept {
    __asm__ __volatile__("" ::: "memory");
}

} // namespace concurrency
