#pragma once
#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_StudentCLL.h"
#include <string>


struct TreeNode {
    Student* student;
    TreeNode* left, * right;
};

class TopStudentTree {
    string treeName;
    TreeNode* root;

    void insert(TreeNode* parent, TreeNode* newnode);

public:

    TopStudentTree();
    TopStudentTree(string treeName);

    TreeNode* getRoot();

    /// <summary>
    /// Creating a new tree node and inserting into Binary Search Tree (BST)
    /// </summary>
    /// <param name="sutdentid"></param>
    /// <param name="name"></param>
    /// <param name="totalScore"></param>
    void insertNewNode(Student* student);

    ~TopStudentTree();
};
