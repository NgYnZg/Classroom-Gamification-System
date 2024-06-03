#pragma once
#include "StudentAnswered.h"
#include <string>
#include<vector>

using namespace std;

struct Student {
	int studentid;
	double totalScore;
	string name;
	StudentAnswered* answered;

	Student();
	Student(int studentid, string name);
};

struct CLLnode {
	Student* student;
	CLLnode* next;

	CLLnode();
	CLLnode(Student* student);
};

class StudentCLL {
	//data
	int size;
	string cllName;
	CLLnode* head, * tail;


	//Create new node
	CLLnode* createNewNode(int studentid, string name);

public:
	//Get Set Methods
	// //Get head node
	CLLnode* getHead() {
		return head;
	}
	//Get tail node
	CLLnode* getTail() {
		return tail;
	}
	//Get size of the list
	int getSize() {
		return size;
	}
	//Set head node
	void setHead(CLLnode* head) {
		this->head = head;
	}
	//Set tail node
	void setTail(CLLnode* tail) {
		this->tail = tail;
	}

	//Constructor
	StudentCLL(string cllName);

	//Insert node at the head
	void insertHead(string name);

	//Insert node at the tail
	void insertTail(string name);

	//Delete node using studentid
	CLLnode* deleteNode(int studentid);

	//Delete node using name
	CLLnode* deleteNode(string name);

	//Search node using studentid
	CLLnode* search(int studentid);

	//Search node using name
	CLLnode* search(string name);

	//Inserting student score
	void score(CLLnode* current, int questionid, double score);

	//Display list
	void display();
};