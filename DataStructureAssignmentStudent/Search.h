#pragma once

#include "StudentAnswered.h"
#include "StudentCLL.h"
#include "TopStudentTree.h"
#include <iostream>
#include "answered.h"
using namespace std;

class Search {
private:
    AnsweredStack* answeredStack;
    StudentCLL* studentCLL;
    StudentAnswered* studentAnswered;

public:
    // Constructor
    Search() : answeredStack(nullptr), studentCLL(nullptr) {}

    Search(AnsweredStack* aStack, StudentCLL* sCLL)
        : answeredStack(aStack), studentCLL(sCLL){}

    // Search for a student's overall score and answered questions
    void searchStudent(int studentId) {
        CLLnode* studentNode = studentCLL->search(studentId);
        StudentAnswered* sAnswered = studentNode->student->answered;
        if (studentNode == nullptr) {
            cout << "Student not found." << endl;
            return;
        }

        cout << "Student ID: " << studentNode->student->studentid << endl;
        cout << "Student Name: " << studentNode->student->name << endl;

        displayStudentRanking(studentNode);
        displayAnsweredQuestions(studentId);
        cout << "Overall Score: " << studentNode->student->totalScore << endl;
    }

private:
    // Display the student's ranking
    void displayStudentRanking(CLLnode* studentNode) {
        CLLnode* array[300]; // Assuming a maximum of 300 students
        int count = 0;
        CLLnode* current = studentCLL->getHead();
        if (!current) return; // If the list is empty, return

        do {
            array[count++] = current;
            current = current->next;
        } while (current != studentCLL->getHead() && count < 300);

        // Sort the array based on the total score (simple bubble sort for simplicity)
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if (array[j]->student->totalScore < array[j + 1]->student->totalScore) {
                    CLLnode* temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }

        // Find and display the student's ranking
        for (int i = 0; i < count; ++i) {
            if (array[i]->student->studentid == studentNode->student->studentid) {
                cout << "Student Rank: " << (i + 1) << endl;
                return;
            }
        }
    }

    // Search for and display a student's answered questions
    void displayAnsweredQuestions(int studentId) {
        Question3* current = answeredStack->peek();
        int questionCount = 0;
        while (current != nullptr && questionCount < 3) {
            if (current->studentid == studentId) {
                displayAnsweredQuestion(current);
                ++questionCount;
            }
            current = current->next; // Move to the next question in the stack
        }
    }

    // Display a student's answered question
    void displayAnsweredQuestion(Question3* question) {
        cout << "--------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Question ID: " << question->questionid << "\n";
        cout << "Question: " << question->question << "\n";
        cout << "Correct Answer: " << question->answer << "\n";
        cout << "Student Answer: " << question->studentanswer << "\n";
        cout << "Original Score: " << question->questionscore << "\n";
        cout << "Student Score: " << question->studentscore << "\n";
        cout << "Discarded: " << (question->discarded ? "Yes" : "No") << "\n\n";
    }
};

class StudentSearch {
private:
    TopStudentTree* topStudentsTree;
    // Helper function to perform an inorder traversal and collect nodes in an array
    void inorderTraversal(TreeNode* node, TreeNode** nodes, int& index, int maxSize) {
        if (node == nullptr || index >= maxSize) return;
        inorderTraversal(node->left, nodes, index, maxSize);
        if (index < maxSize) {
            nodes[index++] = node;
        }
        inorderTraversal(node->right, nodes, index, maxSize);
    }
    // Helper function to sort the nodes array by totalScore in descending order
    void sortNodesByScore(TreeNode** nodes, int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (nodes[j]->student->totalScore < nodes[j + 1]->student->totalScore) {
                    TreeNode* temp = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = temp;
                }
            }
        }
    }
public:
    StudentSearch(TopStudentTree* tree) : topStudentsTree(tree) {}
    bool isTop30Winner(int studentid) {
        const int maxSize = 1000; // Assuming we won't have more than 1000 students
        TreeNode* nodes[maxSize];
        int index = 0;
        inorderTraversal(topStudentsTree->getRoot(), nodes, index, maxSize);
        // Sort nodes by totalScore in descending order
        sortNodesByScore(nodes, index);
        // Check if the student's ID is within the top 30 nodes
        int limit = (index < 30) ? index : 30;
        for (int i = 0; i < limit; ++i) {
            if (nodes[i]->student->studentid == studentid) {
                return true;
            }
        }
        return false;
    }
};

