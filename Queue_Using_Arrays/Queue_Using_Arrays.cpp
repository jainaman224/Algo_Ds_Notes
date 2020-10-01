#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Queue {
 public:
  // Initialize queue of maximum size 'capacity'
  explicit Queue(size_t capacity) : entries_(capacity) {}

  // Enqueue function
  void Enqueue(int x) {
    if (tail_ == entries_.size()) {
      // If number of elements in queue is equal to maximum capacity
      if (num_queue_elements == entries_.size()) {
        throw length_error("queue overflow");
        return;
      } else {
        // If number of elements in queue less than maximum queue size,
        // rearrange
        rotate(entries_.begin(), entries_.begin() + head_, entries_.end());
        head_ = 0, tail_ = num_queue_elements;
      }
    }

    entries_[tail_] = x;
    ++tail_, ++num_queue_elements;
  }

  // Dequeue function
  int Dequeue() {
    // No elements in queue
    if (!num_queue_elements) {
      throw length_error("empty queue");
    }
    --num_queue_elements;
    int ret = entries_[head_];
    ++head_;
    return ret;
  }

  // Size function
  size_t size() const { return num_queue_elements; }

  // Check for emptiness
  bool isEmpty() { return num_queue_elements == 0; }

  // Display all elements in queue
  void display() {
    for (int i = head_; i < tail_; ++i) {
      cout << entries_[i] << " ";
    }
    cout << endl;
  }

 private:
  size_t head_ = 0, tail_ = 0, num_queue_elements = 0;
  vector<int> entries_;
};

int main() {
  // Initialize queue of size 5
  Queue q(5);
  // Enqueue 3 elements
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);
  // Print size
  cout << q.size() << "\n";
  // Print all elements
  q.display();
  // Check for emptiness, and Dequeue
  if (!q.isEmpty()) q.Dequeue();
  // Print size
  cout << q.size() << "\n";
  // Print all elements
  q.display();
  // Enqueue 3 more elements
  q.Enqueue(4);
  q.Enqueue(5);
  q.Enqueue(6);
  // Print size
  cout << q.size() << "\n";
  // Print all elements
  q.display();
  // Enqueue one more element -> Will throw error, since maximum size exceeeded
  /*
  q.Enqueue(7);
  // Print size
  cout << q.size() << "\n";
  // Print all elements
  q.display();
  */
  return 0;
}

/***** OUTPUT *****
3
1 2 3
2
2 3
5
2 3 4 5 6
******************/
