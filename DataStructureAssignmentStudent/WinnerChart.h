#pragma once
#include "TopStudentTree.h"
#include "WinnerStack.h"

class DisplayWinner {
    TreeNode* winnerStudent;

    //Store winners into an array
    void treeToList(TreeNode* current, WinnerStack* winnerStack) {
        if (current == NULL) {
            return;
        }
        else {
            treeToList(current->left, winnerStack);
            winnerStack->push(current->student);
            treeToList(current->right, winnerStack);
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////
    // Function to get the height of the tree
    int getHeight(int nodeCount) {
        int height = (log2(nodeCount + 1)+1);
        cout << "Height : " << height << endl;
        return height;
    }


    // Function to print spaces
    void printSpaces(int count) {
        for (int i = 0; i < count; ++i) {
            cout << " ";
        }
    }

    // Function to print the tree in a structured ASCII format
    void printLevel(WinnerStudent* current, int height) {


        for (int i = 0; i < height; i++) {
            int count = 0;
            while (count < pow(2, i) && current !=NULL) {
                printSpaces(4 * (height - i));
                cout << current->student->name << " (" << current->student->totalScore << ")";
                current = current->next;
                count++;
            }
            cout << endl;

            //printing | (correct)
            int j = 0;
            while(j <= i){
                printSpaces(4 * (height - i) + 2);
                cout << "|";
                j++;
            }
            cout << endl;
            int k = 0;
            while (k <= i) {
                printSpaces(4 * (height - i) - 2);
                cout << "----";
                k++;
            }
            cout << endl;

        }
    }
    void printWinner(WinnerStudent* winner) {
        int margin = 60, word = 4, horLine = 10; //half of the chart
        printSpaces(56);
        cout << winner->student->name << endl;
        for (int level = 0; level < 4; level++) {

        }
    }

    void print30Winner(WinnerStudent* winner, int margin, int horLine, int level) {
        
        printSpaces(120 / pow(2,level) - 1); cout << "|"; cout << endl;
        printSpaces(120 - (4 * (4 - level)) - 1); 
        
        for (int j = 0; j < pow(2, level); j++) {
            cout << "|"; printSpaces(horLine / pow(2, level));
        }cout << endl;
        
        
        for (int i = 0; i < pow(2, level + 1); i++) {
            printSpaces(margin / (level + 2) - 1); cout << "|";
        } cout << endl;
        for (int coutLine = 0; coutLine < 4; coutLine++) {

        }
    }
    void printTree(WinnerStack* winnerList) {
        int height = getHeight(winnerList->getSize());
        printLevel(winnerList->peek(), height);
    }

public:
    DisplayWinner(TreeNode* winnerStudent) {
        this->winnerStudent = winnerStudent;
    }

    void loadWinnerList() {
        WinnerStack* winnerList = new WinnerStack();
        int count = 0;
        if (winnerStudent == NULL)
            return;


        treeToList(winnerStudent, winnerList);

        printTree(winnerList);
        return;
    }
    
};