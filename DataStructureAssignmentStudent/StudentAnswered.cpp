#include "StudentAnswered.h"

using namespace std;


StudentAnswered::StudentAnswered() {
	this->front = this->rear = nullptr;
	int size = 0;
}


Node* StudentAnswered::peek() {
	return this->front;
}


Node* StudentAnswered::createNewNode(int questionid) {
	Node* newnode = new Node;
	newnode->questionid = questionid;
	newnode->next = nullptr;
	return newnode;
}


void StudentAnswered::enqueue(int questionid) {
	Node* newnode = createNewNode(questionid);

	if (front == nullptr) {
		front = rear = newnode;
	}
	else {
		rear->next = newnode;
		rear = newnode;
	}
	size++;

}


void StudentAnswered::dequeue() {
	if (front == NULL) {
		cout << "No node to remove from the front!!";
		return;
	}

	Node* temp = front;
	front = front->next;

	if (front == NULL) {
		rear = NULL;
	}
	delete temp;
	size--;
}

StudentAnswered::~StudentAnswered() {
	cout << "Answered question id list has been destroyed" << endl;
}