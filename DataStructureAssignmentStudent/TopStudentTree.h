#pragma once
#include <string>

using namespace std;

struct TreeNode {
    string name;
    int studentid;
    double totalScore;
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
    void insertNewNode(int studentid, string name, double totalScore);

    /// <summary>
    /// Printing the tree in an inorder traversal
    /// </summary>
    /// <param name="current">Root of the tree; </param>
    void inorder(TreeNode* current);
    ~TopStudentTree();
};
