#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_TopStudentTree.h"
#include <iostream>



TopStudentTree::TopStudentTree() {
    this->treeName = "";
}


TopStudentTree::TopStudentTree(string treeName) {
    this->treeName = treeName;
}

TreeNode* TopStudentTree::getRoot() {
    return root;
}


void TopStudentTree::insertNewNode(Student* student) {
    TreeNode* newnode = new TreeNode();
    newnode->student = student;
    newnode->left = newnode->right = nullptr;

    if (root == NULL) {
        root = newnode;
        return;
    }
    insert(root, newnode);
}


void TopStudentTree::insert(TreeNode* parent, TreeNode* newnode) {
    if (newnode->student->totalScore < parent->student->totalScore) {
        if (parent->left == NULL) {
            parent->left = newnode;
            return;
        }
        insert(parent->left, newnode);
    }
    else if (newnode->student->totalScore > parent->student->totalScore) {
        if (parent->right == NULL) {
            parent->right = newnode;
            return;
        }
        insert(parent->right, newnode);
    }
    else {
        if (newnode->student->studentid < parent->student->studentid) {
            if (parent->left == NULL) {
                parent->left = newnode;
                return;
            }
            insert(parent->left, newnode);
        }
        else if (newnode->student->studentid > parent->student->studentid) {
            if (parent->right == NULL) {
                parent->right = newnode;
                return;
            }
            insert(parent->right, newnode);
        }
    }
}



TopStudentTree::~TopStudentTree() {
    cout << "Tree " << treeName << " has been deleted!" << endl;
}