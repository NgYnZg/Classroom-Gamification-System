#pragma once
#include "StudentAnswered.h"
#include <string>

using namespace std;

struct Student {
	int studentid;
	int totalScore;
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


	/// <summary>
	/// Adding totalScore of the student that has answered or discared the question,
	/// enqueue the question id into the answered queue of the student.
	/// </summary>
	/// <param name="current"> Current node of answering student </param>
	/// <param name="score"> Scored points</param>
	void score(int questionid, int score);
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

	//Constructor
	StudentCLL(string cllName);

	/// <summary>
	/// Creating a new Circular Linked List (CLL) node based on the student's name and inserting the node into the list
	/// </summary>
	/// <param name="studentname"></param>
	void insertHead(string name);

	/// <summary>
	/// Deletion of Circular Linked List (CLL) node at the head
	/// </summary>
	/// <returns name="deletedStudent"></returns>
	CLLnode* deleteHead();

	/// <summary>
	/// Deletion of Circular Linked List (CLL) node based on student name
	/// </summary>
	/// <param name="studentid"></param>
	/// <returns name="deletedStudent"></returns>
	CLLnode* deleteNode(string name);

	/// <summary>
	/// Searching Circular Linked List (CLL) node using studentid
	/// </summary>
	/// <param name="studentid"></param>
	/// <returns>Returns a CLLnode that holds student node </returns>
	CLLnode* search(int studentid);

	/// <summary>
	/// Searching a Circular Linked List (CLL) node using name
	/// </summary>
	/// <param name="name"> Name of the Student</param>
	/// <returns> Returns a CLLnode that holds student node </returns>
	CLLnode* search(string name);


	/// <summary>
	/// Displaying all students' name and total score
	/// </summary>
	void display();
};
