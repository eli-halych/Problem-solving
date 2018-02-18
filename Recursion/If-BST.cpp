/*
 *
 * Check if a binary tree is binary search tree(BST)
 *
 */

#include <iostream>


class binaryTree {
public:
    bool publicIsBinaryTree();

private:
    struct binaryTreeNode{
        int data;
        binaryTreeNode * left;
        binaryTreeNode * right;
    };
    typedef binaryTreeNode * treePtr;
    treePtr _root;
    bool privateIsBinaryTree(treePtr rootPtr);
};

bool binaryTree::publicIsBinaryTree() {
    return privateIsBinaryTree(_root);
}

bool binaryTree::privateIsBinaryTree(treePtr rootPtr) {

    // false <- NO or NULL
    // true <- YES

    // consider each node has 2 leafs

    if (rootPtr == NULL) return false;
    if (rootPtr->right == NULL && rootPtr->left == NULL) return true;

    bool left = privateIsBinaryTree(rootPtr->left);
    bool right = privateIsBinaryTree(rootPtr->right);
    bool condition = (rootPtr->left->data) < (rootPtr->data) < (rootPtr->right->data);

    return condition ? left && right : false;
}


int main() {
    return 0;
}