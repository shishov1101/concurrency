#include <iostream>
#include <thread>
#include <vector>
#include <concurrency/spinlock.hpp>

concurrency::spinlock lock;
int counter = 0;

void worker() {
    for (int i = 0; i < 10000; ++i) {
        lock.lock();
        ++counter;
        lock.unlock();
    }
}

int main() {
    constexpr int num_threads = 4;
    std::vector<std::thread> threads;
    
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(worker);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "Counter value: " << counter << std::endl;
    return 0;
}
