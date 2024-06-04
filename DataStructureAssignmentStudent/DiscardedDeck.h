#pragma once
#include <iostream>
#include <string>
#include <functional>

using namespace std;

struct Question2 {
    string question;
    bool discarded;
    int discardedstudentid;
    int questionid;
    string answer;
    int questionscore;

    Question2(const string& q, bool d = true, int dsid = 0, int qid = 0, const string& a = "", int qs = 0);
};

struct Node {
    Question2 card;
    Node* next;
    Node* prev;
    Node(Question2 c);
};

class DiscardedDeck {
private:
    Node* head;
    Node* tail;

    Node* merge(Node* left, Node* right, const function<bool(const Question2&, const Question2&)>& comp);
    Node* mergeSort(Node* head, const function<bool(const Question2&, const Question2&)>& comp);
    void updateTail();

public:
    DiscardedDeck();
    void discardCard(const Question2& card);
    void displayDiscardedCards() const;
    Question2 selectDiscardedCard(int index);
    void sortScore();
    void searchKeyword(const string& keyword) const;
    ~DiscardedDeck();
};
