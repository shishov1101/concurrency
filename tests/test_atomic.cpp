#include <gtest/gtest.h>
#include <concurrency/atomic/atomic.hpp>

TEST(AtomicTest, BasicOperations) {
    concurrency::atomic a{42};
    EXPECT_EQ(a.load(), 42);
    
    a.store(100);
    EXPECT_EQ(a.load(), 100);
    
    int expected = 100;
    EXPECT_TRUE(a.compare_exchange_strong(expected, 200));
    EXPECT_EQ(a.load(), 200);
    
    EXPECT_EQ(a.fetch_add(10), 200);
    EXPECT_EQ(a.load(), 210);
}

TEST(AtomicTest, Operators) {
    concurrency::atomic a;
    a = 50;
    EXPECT_EQ(static_cast<int>(a), 50);
    
    ++a;
    EXPECT_EQ(a.load(), 51);
    
    --a;
    EXPECT_EQ(a.load(), 50);
}

TEST(AtomicTest, ARM64Alignment) {
    concurrency::atomic a;
    ASSERT_EQ(reinterpret_cast<uintptr_t>(&a) % 4, 0) << "Atomic variable must be 4-byte aligned";
}
