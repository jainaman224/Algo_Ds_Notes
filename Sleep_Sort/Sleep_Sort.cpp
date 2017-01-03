#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

std::mutex lock;

void sortThread(const int x) {
  std::chrono::milliseconds duration{ x * 10 };

  std::this_thread::sleep_for(duration);

  lock.lock();
  std::cout << x << " ";
  lock.unlock();
}

int main() {
  std::vector<int> x = { 2, 4, 3, 1, 6, 8, 4 };
  std::vector<std::thread> threads;

  for (const auto &i : x) {
    threads.push_back(std::thread(sortThread, i));
  }

  for (auto it = threads.begin(); it != threads.end(); ++it) {
    it->join();
  }

  std::cout << "\n";
}

// Output
// 1 2 3 4 4 6 8
