#pragma once

#include <iostream>
#include <iomanip>
#include "StudentCLL.h"

using namespace std;
struct WinnerNode
{
    string studentName;
    int totalScore;
    WinnerNode* left;
    WinnerNode* right;
};

class WinnerTree
{
    WinnerNode* root;
    string treename = "";

public:
    WinnerTree(string treename)
    {
        root = nullptr;
        this->treename = treename;
    }
    ~WinnerTree()
    {
        cout << "\n" << treename << " is deleted from the memory!" << endl;
    }

    void buildTree(Student** arrayPointer, int arraySize)
    {
        cout << arrayPointer[0]->name << endl;
        root = insertWinner(0, arraySize, arrayPointer);
    }

    WinnerNode* insertWinner(int currentIndex, int arraySize, Student**& arrayPointer) {
        cout << arrayPointer[0]->name << endl;

        if (currentIndex < arraySize && arrayPointer[currentIndex] != nullptr) {
            WinnerNode* temp = new WinnerNode();
            temp->studentName = arrayPointer[currentIndex]->name;
            temp->totalScore= arrayPointer[currentIndex]->totalScore;
            temp->left = insertWinner( 2 * currentIndex + 1, arraySize, arrayPointer);
            temp->right = insertWinner(2 * currentIndex + 2, arraySize, arrayPointer);
            return temp;
        }
        return nullptr;
    }

    void printTree()
    {

        if (root == nullptr) return;

        //Level 0
        cout << setw(76) << root->studentName << endl;
        cout << setw(74) << root->totalScore<< endl;
        cout << setw(73) << "|"
            << endl;
        cout << setw(110) << "+------------------------------------------------------------------------+"
            << endl;


        //Level 1
        cout
            << setw(37) << "|" << setw(73) << "|"
            << endl;
        cout
            << setw(41) << root->left->studentName << setw(72) << root->right->studentName
            << endl;
        cout << setw(38) << root->left->totalScore << setw(73) << root->right->totalScore
            << endl;


        //Level 2
        cout
            << setw(37) << "|" << setw(73) << "|"
            << endl;
        cout
            << setw(46) << "+-------------------+" << setw(74) << "+-------------------+"
            << endl;
        cout
            << setw(26) << "|" << setw(20) << "|" << setw(54) << "|" << setw(20) << "|"
            << endl;
        cout
            << setw(30) << root->left->left->studentName << setw(19) << root->left->right->studentName << setw(55)
            << root->right->left->studentName << setw(19) << root->right->right->studentName
            << endl;
        cout
            << setw(27) << root->left->left->totalScore << setw(20) << root->left->right->totalScore << setw(54)
            << root->right->left->totalScore << setw(20) << root->right->right->totalScore
            << endl;
        //Level 3
        cout
            << setw(26) << "|" << setw(20) << "|" << setw(54) << "|" << setw(20) << "|"
            << endl;

        cout
            << setw(27) << "+-----------------+" << setw(36) << "+-----------------+" << setw(38) << "+-----------------+"
            << setw(36) << "+-----------------+"
            << endl;
        cout
            << setw(9) << "|" << setw(18) << "|" << setw(18) << "|" << setw(18) << "|" << setw(20) << "|" << setw(18) << "|"
            << setw(18) << "|" << setw(18) << "|"
            << endl;
        cout
            << setw(13) << root->left->left->left->studentName << setw(17) << root->left->left->right->studentName << setw(19)
            << root->left->right->left->studentName << setw(17) << root->left->right->right->studentName << setw(21)
            << root->right->left->left->studentName << setw(17) << root->right->left->right->studentName << setw(19)
            << root->right->right->left->studentName << setw(17) << root->right->right->right->studentName
            << endl;
        cout
            << setw(10) << root->left->left->left->totalScore << setw(18) << root->left->left->right->totalScore << setw(18)
            << root->left->right->left->totalScore << setw(18) << root->left->right->right->totalScore << setw(20)
            << root->right->left->left->totalScore << setw(18) << root->right->left->right->totalScore << setw(18)
            << root->right->right->left->totalScore << setw(18) << root->right->right->right->totalScore
            << endl;

        //Level 4
        cout
            << setw(9) << "|" << setw(18) << "|" << setw(18) << "|" << setw(18) << "|" << setw(20) << "|" << setw(18) << "|"
            << setw(18) << "|" << setw(18) << "|"
            << endl;
        cout
            << setw(14) << "+---------+" << setw(18) << "+---------+" << setw(18) << "+---------+" << setw(18) << "+---------+"
            << setw(20) << "+---------+" << setw(18) << "+---------+" << setw(18) << "+---------+" << setw(18) << "+---------+"
            << endl;
        cout
            << setw(4) << "|" << setw(10) << "|" << setw(8) << "|" << setw(10) << "|" << setw(8) << "|" << setw(10) << "|" << setw(8)
            << "|" << setw(10) << "|" << setw(10) << "|" << setw(10) << "|" << setw(8) << "|" << setw(10) << "|"
            << setw(8) << "|" << setw(10) << "|" << setw(8) << "|"
            << endl;
        cout
            << root->left->left->left->left->studentName << " " << root->left->left->left->right->studentName << " " // left side //
            << root->left->left->right->left->studentName << " " << root->left->left->right->right->studentName << " " //
            << root->left->right->left->left->studentName << " " << root->left->right->left->right->studentName << " " //
            << root->left->right->right->left->studentName << " " << root->left->right->right->right->studentName << "   "
            << root->right->left->left->left->studentName << " " << root->right->left->left->right->studentName << " "// right side
            << root->right->left->right->left->studentName << " " << root->right->left->right->right->studentName << " "
            << root->right->right->left->left->studentName << " " << root->right->right->left->right->studentName << " "
            << root->right->right->right->left->studentName
            << endl;

        cout
            << setw(5) << root->left->left->left->left->totalScore << setw(10) << root->left->left->left->right->totalScore
            << setw(8) << root->left->left->right->left->totalScore << setw(10) << root->left->left->right->right->totalScore
            << setw(8) << root->left->right->left->left->totalScore << setw(10) << root->left->right->left->right->totalScore
            << setw(8) << root->left->right->right->left->totalScore << setw(10) << root->left->right->right->right->totalScore
            << setw(10) << root->right->left->left->left->totalScore << setw(10) << root->right->left->left->right->totalScore // right side
            << setw(8) << root->right->left->right->left->totalScore << setw(10) << root->right->left->right->right->totalScore
            << setw(8) << root->right->right->left->left->totalScore << setw(10) << root->right->right->left->right->totalScore
            << setw(8) << root->right->right->right->left->totalScore
            << endl;
    }



private:
    int findHeight(WinnerNode* current)
    {
        if (current == nullptr)
            return -1;
        return 1 + max(findHeight(current->left), findHeight(current->right));
    }


};
