#include <gtest/gtest.h>
#include <thread>
#include <vector>
#include <concurrency/spinlock.hpp>

TEST(SpinlockTest, BasicLocking) {
    concurrency::spinlock lock;
    int shared = 0;
    
    auto worker = [&]() {
        for (int i = 0; i < 1000; ++i) {
            lock.lock();
            ++shared;
            lock.unlock();
        }
    };
    
    std::thread t1(worker);
    std::thread t2(worker);
    
    t1.join();
    t2.join();
    
    EXPECT_EQ(shared, 2000);
}

TEST(SpinlockTest, TryLock) {
    concurrency::spinlock lock;
    EXPECT_TRUE(lock.try_lock());
    EXPECT_FALSE(lock.try_lock());
    lock.unlock();
    EXPECT_TRUE(lock.try_lock());
}
