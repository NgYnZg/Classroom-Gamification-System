#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>
#include "LinkedList.h"

using namespace std;

// Constructor to initialize an empty list
LinkedList::LinkedList() : head(nullptr), size(0) {}

// Destructor to clean up memory
LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to add a question to the end of the list
void LinkedList::addQuestion(Question1* q) {
    Node* newNode = new Node{ q, nullptr };
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

// Function to display all questions in the list
void LinkedList::displayQuestions() const {
    Node* temp = head;
    while (temp) {
        cout << "Question ID: " << temp->question->questionid << endl;
        cout << "Question: " << temp->question->question << endl;
        cout << "Score: " << temp->question->questionscore << endl;
        temp = temp->next;
    }
}

Question1* LinkedList::peek() {
    return this->head->question;
}
Question1* LinkedList::displayAndRemoveFirstQuestion() {
    if (!head) {
        cout << "No questions available." << endl;
        return new Question1(); // Return a default-constructed Question if no questions available
    }

    // Display the first question details except the answer
    cout << "Question ID: " << head->question->questionid << endl;
    cout << "Question: " << head->question->question << endl;
    cout << "Score: " << head->question->questionscore << endl;

    // Remove the first question from the list
    Node* temp = head;
    head = head->next;
    Question1* removedQuestion = temp->question; // Store the removed question
    delete temp; // Delete the node, which contains the entire Question object
    size--;

    return removedQuestion; // Return the removed question


}








