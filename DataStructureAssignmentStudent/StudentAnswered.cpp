#include "StudentAnswered.h"

using namespace std;


StudentAnswered::StudentAnswered() {
	this->front = this->rear = nullptr;
	int size = 0;
}

/// <summary>
/// Peeking at the front of the queue
/// </summary>
/// <returns> Returns a question id node</returns>
Node* StudentAnswered::peek() {
	return this->front;
}


Node* StudentAnswered::createNewNode(int questionid) {
	Node* newnode = new Node;
	newnode->questionid = questionid;
	newnode->next = nullptr;
	return newnode;
}

/// <summary>
/// Enqueue a new question id into the queue
/// </summary>
/// <param name="questionid"> question id that the student answered or discarded</param>
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

/// <summary>
/// Dequeue the queue to peek at the next item, 
/// this function does not return anything, 
/// couple with peek() function to read the whole queue
/// </summary>
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