// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template<typename T>
class BST {
 private:
    struct Node {
        T val;
        int c;
        Node* rig;
        Node* lef;
        explicit Node(T val) : val(val), c(1), rig(nullptr), lef(nullptr) {}
    };

 public:
    Node* root;
    BST() : root(nullptr) {}
    int s(T val) {
        return sNode(root, val);
    }
    int sNode(Node* root, T val) {
        if (root == nullptr)
            return 0;
        if (val < root->val)
            return sNode(root->lef, val);
        if (root->val == val)
            return root->c;
        else
            return sNode(root->rig, val);
    }
    int depth() {
        return getDepth(root) - 1;
    }
    int getDepth(Node* root) {
        if (root)
            return std::max(getDepth(root->lef), getDepth(root->rig)) + 1;
        else
            return 0;
    }
    void add(T val) {
        root = insWords(root, val);
    }
    Node* insWords(Node* ptr, T words) {
        if (!ptr) {
            ptr = new Node(words);
        } else if (ptr->val > words) {
            ptr->lef = insWords(ptr->lef, words);
        } else if (ptr->val < words) {
            ptr->rig = insWords(ptr->rig, words);
        } else if (ptr->val == words) {
            ptr->c++;
        }
        return ptr;
    }
};
#endif  // INCLUDE_BST_H_
