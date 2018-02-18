/*
 *
 * Check if a binary tree is a binary search tree(BST).
 * Insert a new node.
 *
 */

#include <iostream>


class binaryTree {
public:
    bool publicIsBST();
    void insert(int num);

private:
    struct binaryTreeNode{
        int data;
        binaryTreeNode * left;
        binaryTreeNode * right;
        binaryTreeNode(int x){
            data = x;
            left = right = NULL;
        }
    };
    typedef binaryTreeNode * treePtr;
    treePtr _root;
    bool privateIsBST(treePtr rootPtr);
    void insert(int num, treePtr& root);
};

//-------------------- isBST
bool binaryTree::publicIsBST() {
    return privateIsBST(_root);
}
bool binaryTree::privateIsBST(treePtr rootPtr) {

    // false <- NO or NULL
    // true <- YES

    // consider each node has 2 leafs

    if (rootPtr == NULL) return false;
    if (rootPtr->right == NULL && rootPtr->left == NULL) return true;

    bool left = privateIsBST(rootPtr->left);
    bool right = privateIsBST(rootPtr->right);
    bool condition = (rootPtr->left->data) < (rootPtr->data) < (rootPtr->right->data);

    return condition ? left && right : false;
}

//-------------------- insert a number
void binaryTree::insert(int num) {
    insert(num, _root);
}
void binaryTree::insert(int num, treePtr& root) {

    if (root == NULL) root = new binaryTreeNode(num);
    else if (num < root->data) {

        if (root->left == NULL) root->left = new binaryTreeNode(num);
        else insert(num, root->left);

    } else if (num > root->data){

        if (root->right == NULL) root->right = new binaryTreeNode(num);
        else insert(num, root->right);

    }
    // else do not insert (num already exists)
}


int main() {

    // search binary tree
    binaryTree bt;
    bt.insert(12);
    bt.insert(5);
    bt.insert(1);
    bt.insert(6);
    bt.insert(20);
    bt.insert(13);
    bt.insert(25);
    bt.insert(23);
    bt.insert(30);

//    std::cout << bt.publicIsBST(); // works for search binary tree

    return 0;
}
