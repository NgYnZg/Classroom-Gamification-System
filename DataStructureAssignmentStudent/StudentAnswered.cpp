#include "StudentAnswered.h"

using namespace std;


StudentAnswered::StudentAnswered() {
	this->front = this->rear = nullptr;
	int size = 0;
}


STQNode* StudentAnswered::peek() {
	return this->front;
}


STQNode* StudentAnswered::createNewNode(int questionid) {
	STQNode* newSTQNode = new STQNode;
	newSTQNode->questionid = questionid;
	newSTQNode->next = nullptr;
	return newSTQNode;
}


void StudentAnswered::enqueue(int questionid) {
	STQNode* newSTQNode = createNewNode(questionid);

	if (front == nullptr) {
		front = rear = newSTQNode;
	}
	else {
		rear->next = newSTQNode;
		rear = newSTQNode;
	}
	size++;

}


void StudentAnswered::dequeue() {
	if (front == NULL) {
		cout << "No STQNode to remove from the front!!";
		return;
	}

	STQNode* temp = front;
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