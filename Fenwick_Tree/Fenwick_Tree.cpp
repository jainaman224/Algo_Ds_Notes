#include <iostream>

const int MAX = 100000; // Let's assume the array size is 100000

int N; // N is the size of the whole array
int bit[MAX];

int lowbit(int x) {
  return x & -x;
}

void update(int index, int value) {
  // add "value" to the index-th element
  for( ; index <= N ; index += lowbit(index)) {
    bit[index] += value;
  }
}

int query(int index) {
  // query returns the prefix sum of the first element to the index-th element
  int ret = 0;
  for( ; index > 0 ; index -= lowbit(index)) {
    ret += bit[index];
  }
  return ret;
}

int main(){

  N = 10;

  // WARNING: the index of the first element is 1
  update(2, 100);
  update(5, 1000);
  update(8, 10);

  std::cout << query(1) << std::endl;  // 0
  std::cout << query(2) << std::endl;  // 100
  std::cout << query(3) << std::endl;  // 100
  std::cout << query(4) << std::endl;  // 100
  std::cout << query(5) << std::endl;  // 1100
  std::cout << query(6) << std::endl;  // 1100
  std::cout << query(7) << std::endl;  // 1100
  std::cout << query(8) << std::endl;  // 1110
  std::cout << query(9) << std::endl;  // 1110
  std::cout << query(10) << std::endl; // 1110

  return 0;
}
