#pragma once
#include "StudentCLL.h"

using namespace std;

struct WinnerStudent{
	//data
	Student* student;

	WinnerStudent* next; // Pointer to the next winneruestion in the stack

	
};

class WinnerStack
{
private:
	WinnerStudent* top;
	int size;

public:
	WinnerStack() : top(nullptr), size(0) {}

	int getSize() {
		return size;
	}

	void push(Student* winner) {
		WinnerStudent* newWinner = new WinnerStudent();
		newWinner->student = winner;
		newWinner->next = top;
		top = newWinner;
		size++;
	}

	WinnerStudent* peek() {
		return top;
	}

	WinnerStudent* pop() {
		if (top == nullptr) {
			return nullptr;
		}
		WinnerStudent* temp = top;
		top = top->next;
		temp->next = nullptr;
		size--;
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

	void printList() {
		WinnerStudent* current = peek();
		cout << "Winner Students: " << endl;
		while (current != NULL) {
			cout << "Student name: " << current->student->name << endl;
			current = current->next;
		}
	}

};