#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Node {
	int questionid;
	Node* next;
};

//Queue Structure (FIFO)
class StudentAnswered {
	int size;
	Node *front, *rear;

	Node* createNewNode(int questionid);
public:
	StudentAnswered();

	void enqueue(int questionid);
	void dequeue();
	Node* peek();

	~StudentAnswered();
};