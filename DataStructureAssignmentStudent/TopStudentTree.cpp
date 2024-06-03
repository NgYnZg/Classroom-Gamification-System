#include "TopStudentTree.h"
#include <iostream>

TopStudentTree::TopStudentTree(string treeName) {
    this->treeName = treeName;
}

void TopStudentTree::insertNewNode(int sutdentid, string name, double totalScore) {
    TreeNode* newnode = new TreeNode();
    newnode->name = name;
    newnode->totalScore = totalScore;
    newnode->left = newnode->right = nullptr;

    if (root == NULL) {
        root = newnode;
        return;
    }
    insert(root, newnode);
}

void TopStudentTree::insert(TreeNode* parent, TreeNode* newnode) {
    if (newnode->totalScore < parent->totalScore) {
        if (parent->left == NULL) {
            parent->left = newnode;
            return;
        }
        insert(parent->left, newnode);
    }
    else if (newnode->totalScore > parent->totalScore) {
        if (parent->right == NULL) {
            parent->right = newnode;
            return;
        }
        insert(parent->right, newnode);
    }
    else {
        if (newnode->studentid < parent->studentid) {
            if (parent->left == NULL) {
                parent->left = newnode;
                return;
            }
            insert(parent->left, newnode);
        }
        else if (newnode->totalScore > parent->totalScore) {
            if (parent->right == NULL) {
                parent->right = newnode;
                return;
            }
            insert(parent->right, newnode);
        }
    }
}

void TopStudentTree::inorder(TreeNode* current) {

    if (current == NULL)
        return;

    // Traverse left subtree
    inorder(current->left);

    // Visit node
    cout << current->name << " ";

    // Traverse right subtree
    inorder(current->right);

}

TopStudentTree::~TopStudentTree() {
    cout << "Tree " << treeName << " has been deleted!" << endl;
}