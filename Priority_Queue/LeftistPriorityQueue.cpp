#include <iostream>
#include <algorithm>

struct Leftist {
  Leftist *left, *right;
  int dis, value, size;
  Leftist(int val = 0) {
    left = NULL, right = NULL;
    dis = 0, value = val, size = 1;
  }
  ~Leftist() {
    delete left;
    delete right;
  }
};

Leftist* merge(Leftist *x, Leftist *y) {
  if (x == NULL) return y;
  if (y == NULL) return x;
  if (y->value < x->value) { // Use > here if you want a max priority queue
    std::swap(x, y);
  }
  x->size += y->size;
  x->right = merge(x->right, y);
  if (x->left == NULL && x->right != NULL) {
    std::swap(x->left, x->right);
  } else if(x->right != NULL && x->left->dis < x->right->dis) {
    std::swap(x->left, x->right);
  }
  if (x->right == NULL) {
    x->dis = 0;
  } else {
    x->dis = x->right->dis + 1;
  }
  return x;
}

Leftist* delete_root(Leftist *T) {
  Leftist *my_left = T->left;
  Leftist *my_right = T->right;
  T->left = T->right = NULL;
  delete T;
  return merge(my_left, my_right);
}

int main() {
  
  Leftist *my_tree = new Leftist(10); // create a tree with root = 10

  // adding a node to a tree is the same as creating a new tree and merge them together
  my_tree = merge(my_tree, new Leftist(100));   // push 100 
  my_tree = merge(my_tree, new Leftist(10000)); // push 10000
  my_tree = merge(my_tree, new Leftist(1));     // push 1
  my_tree = merge(my_tree, new Leftist(1266));  // push 1266

  while (my_tree != NULL) {
    std::cout << my_tree->value << std::endl;
    my_tree = delete_root(my_tree);
  }

  return 0;
}
