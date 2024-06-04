#pragma once
#include <iostream>

using namespace std;

struct Question1
{
    int questionid;
    string question;
    string answer;
    int questionscore;

    Question1() {
        this->questionid = 0;
        this->question = "";
        this->answer = "";
        this->questionscore = 0;
    }
    Question1(int questionid, string question, string answer, int questionscore) {
        this->questionid = questionid;
        this->question = question;
        this->answer = answer;
        this->questionscore = questionscore;
    }
};

class LinkedList {
    struct Node {
        Question1* question;
        Node* next;
    };

    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    void addQuestion(Question1* q);  // Add question to end of the list
    void displayQuestions() const;        // Display all questions
    Question1* displayAndRemoveFirstQuestion(); // Display and remove the first question
    static void readQuestionsFromFile(const string& filename, LinkedList& list);
};



