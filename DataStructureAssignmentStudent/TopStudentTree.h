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

    void insertNewNode(int studentid, string name, double totalScore);
    void inorder(TreeNode* current);
    ~TopStudentTree();
};
