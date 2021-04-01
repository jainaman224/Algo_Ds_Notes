// #ifndef RB_H
// #define RB_H

// struct Node {
//     Node *parent;
//     Node *right;
//     int data;
//     Node *left;
// };

// class RB_Tree {
//    private:
//     Node *Root;

//    public:
//     RB_Tree();
//     ~RB_Tree();
//     void left_rotate();
//     void right_rotate();
//     void lr_rotate();
//     void rl_rotate();
// };
// #endif  // RB_H
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data{};
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    string color;
};

class RB_TREE {
    Node* Root;

   public:
    RB_TREE();

    Node* GetRoot();

    void InsertNode(int key);

    void RB_Insert_Fixup(Node* z);

    void RemoveNode(Node* parent, Node* curr, int key);

    void Remove(int key);

    void RB_Delete_Fixup(Node* z);

    Node* TreeSearch(int key);

    void LeftRotate(Node* x);

    void RightRotate(Node* x);

    void PreorderTraversal(Node* temp);

    void PostorderTraversal(Node* temp);
};
