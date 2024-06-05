#pragma once
#include <iostream>
using namespace std;
struct Question3
{
	//data
	string question;
	bool discarded;
	int discardedstudentid;
	int questionid;
	string answer; //// Correct answer for the question
	int questionscore;
	int studentid;
	int studentscore;
	string studentanswer;

	Question3* next; // Pointer to the next question in the stack

	Question3(string q, string ans, int qid, int qscore) {
		this->question = q;
		this->discarded= NULL;
		this->discardedstudentid = -1;
		this->questionid = qid;
		this->answer = ans;
		this->questionscore = qscore;
		this->studentid = -1;
		this->studentscore = 0;
		this->next = nullptr;
	}
};

class AnsweredStack
{
private:
	Question3* top;

public:
	AnsweredStack() : top(nullptr) {}

	void push(Question3* q) {
		q->next = top;
		top = q;
	}

	Question3* peek() {
		return top;
	}

	Question3* pop() {
		if (top == nullptr) {
			return nullptr;
		}
		Question3* temp = top;
		top = top->next;
		temp->next = nullptr;
		return temp;
	}
	bool isEmpty() {
		if (top == nullptr) {
			return true;
			cout << "the stack is empty";
		}
		else {
			return false;
		}
	}

	// Display all answered questions
	void display() {
		Question3* current = top;
		while (current != nullptr) {
			cout << "Question ID: " << current->questionid << "\n";
			cout << "Question: " << current->question << "\n";
			cout << "Correct Answer: " << current->answer << "\n";
			cout << "Student Answer: " << current->studentanswer << "\n";
			cout << "Original Score: " << current->questionscore << "\n";
			cout << "Student Score: " << current->studentscore << "\n";
			cout << "Discarded: " << (current->discarded ? "Yes" : "No") << "\n\n";
			current = current->next;
		}
	}

};
int recordAnswer(Question3* q, int studentid, string studentanswer, bool discarded) {
	q->studentid = studentid;
	q->studentanswer = studentanswer;
	q->discarded = discarded;

	// Check if the answer is correct
	if (q->answer == studentanswer) {
		if (discarded) {
			q->studentscore = static_cast<int>(q->questionscore * 0.8);
		}
		else {
			q->studentscore = q->questionscore;
		}

	}
	else {
		q->studentscore = 0;
	}

	return q->questionscore;
}
