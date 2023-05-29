// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template<typename T>
class BST {
 private:
    struct Node {
        T val;
        int count;
        Node* rig;
        Node* lef;
        explicit Node(T val) : val(val), count(1), rig(nullptr), lef(nullptr) {}
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
            return root->count;
        else
            return sNode(root->rig, val);
    }
    int thedepth() {
        return getTheDepth(root) - 1;
    }
    int getTheDepth(Node* root) {
        if (root)
            return std::max(getTheDepth(root->lef), getTheDepth(root->rig)) + 1;
        else
            return 0;
    }
    void add(T val) {
        root = insWords(root, val);
    }
    Node* insWords(Node* nptr, T words) {
        if (!nptr) {
            nptr = new Node(words);
        } else if (nptr->val > words) {
            nptr->lef = insWords(nptr->lef, words);
        } else if (nptr->val < words) {
            nptr->rig = insWords(nptr->rig, words);
        } else if (ptr->val == words) {
            nptr->count++;
        }
        return nptr;
    }
};
#endif  // INCLUDE_BST_H_
