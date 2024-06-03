#include "StudentCLL.h"
#include "TopStudentTree.h"
#include <iostream>

using namespace std;

int main() {
	//Initializing a Circular Linked List called tutorial1
	StudentCLL* tutorial1 = new StudentCLL("tutorial1");

	//Inserting nodes by stating the student names
	//Insert from head
	tutorial1->insertHead("B");
	tutorial1->insertHead("A");

	//Insert from tail
	tutorial1->insertTail("Z");

	//Displaying the total names and scores of the students
	tutorial1->display();

	//Printing the size of the list
	cout << "List size: " << tutorial1->getSize() << endl;

	//getting the node of certain student from the list
	CLLnode* student = tutorial1->search("B");

	//Printing the name of the student
	cout << "Student id of " << student->student->name << " : " << student->student->studentid << endl;
	
	//Inserting score of the student
	tutorial1->score(student, 0, 20);
	tutorial1->score(student, 1, 0);

	/*
	//Printing the first question id of the questions answered by the student
	cout << student->student->answered->peek()->questionid << endl;
	//Move the list into the next one
	student->student->answered->dequeue();
	//Print the second question id
	cout << student->student->answered->peek()->questionid << endl;
	*/


	//Displaying the whole list again
	cout << endl;
	cout << endl;
	cout << endl;
	tutorial1->display();


	TopStudentTree* winnerBST = new TopStudentTree("Winner Tree");
	CLLnode* current = tutorial1->getHead();
	do
	{
		winnerBST->insertNewNode(current->student->studentid, current->student->name, current->student->totalScore);
		cout << "Students in tree: " << current->student->name << endl;
		current = current->next;
	} while (current != tutorial1->getHead());
	

	winnerBST->inorder(winnerBST->getRoot());

}