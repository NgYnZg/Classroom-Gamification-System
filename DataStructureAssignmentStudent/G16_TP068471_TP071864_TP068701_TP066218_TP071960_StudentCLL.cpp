#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_StudentCLL.h";
#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_StudentAnswered.h";
#include <iostream>;

Student::Student() {
	this->studentid = 0;
	this->name = "";
	this->totalScore = 0;
	this->answered = new StudentAnswered();
}
Student::Student(int studentid, string name) {
	this->studentid = studentid;
	this->name = name;
	this->totalScore = 0;
	this->answered = new StudentAnswered();
}


CLLnode::CLLnode() {
	this->next = nullptr;
	this->student = new Student();
}

CLLnode::CLLnode(Student* student) {
	this->next = nullptr;
	this->student = student;
}

StudentCLL::StudentCLL(string cllName) {
	this->head = this->tail = nullptr;
	this->cllName = cllName;
	this->size = 0;
}

CLLnode* StudentCLL::createNewNode(int studentid, string name) {
	Student* newStudent = new Student(studentid, name);
	CLLnode* newNode = new CLLnode(newStudent);
	return newNode;
}

//Insert node at the head
void StudentCLL::insertHead(string studentname) {
	//Creating new node
	CLLnode* newNode = createNewNode(this->size, studentname);
	size++;

	//1. if no nodes in the CLL
	if (this->head == NULL) {
		this->head = this->tail = newNode;
		tail->next = head;
		return;
	}
	//2. if node exist in the CLL
	// steps: point newnode.next to head -> make newnode the new head -> connect tail to the new head
	newNode->next = head;
	head = newNode;
	tail->next = head;
}


//Delete node from tail
void StudentCLL::deleteHead() {
	CLLnode* current = head;

	//If list have is empty
	if (head == nullptr) {
		cout << "There is no node to delete!!" << endl;
		return;
	}

	//If the list only contains one node
	if (head == tail){
		head = tail = nullptr;
		current->next = nullptr;
		size--;
		delete current;
		return;
	}
	else {
	//If the list contains more than one node
	head = head->next;
	tail->next = head;
	current->next = nullptr;
	size--;
	return;
	}
}

//Search node using studentid
CLLnode* StudentCLL::search(int studentid) {
	CLLnode* current = head;

	if (head->student->studentid == studentid) {
		return head;
	}

	//Loop through the list to find the matched student node
	current = current->next;
	while (current != head) {
		//Steps: search through the node to find the node with matched studentid
		if (current->student->studentid == studentid) {
			return current;
		}
		//Incrementing node index
		current = current->next;
	}
	cout << "Student id does not exist!!" << endl;
	return new CLLnode();
}



//Search node using name
CLLnode* StudentCLL::search(string name) {
	CLLnode* current;

	if (head->student->name == name) {
		return head;
	}
	//Loop through the list to find the matched student node
	current = head->next;
	while (current != head) {
		//Steps: search through the node to find the node with matched studentid
		if (current->student->name == name) {
			return current;
		}
		//Incrementing node index
		current = current->next;
	}
	cout << "Student name does not exist!!" << endl;
	return new CLLnode;
}

//Inserting student score
void CLLnode::score(int questionid, int score) {
	this->student->totalScore += score;
	this->student->answered->enqueue(questionid);
}

//Display list
void StudentCLL::display() {
	CLLnode* current = head;

	cout << "Students: " << endl;
	do {
		cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Student ID: " << current->student->studentid<< endl;
		cout << "Total Score: " << current->student->totalScore << endl;
		cout << "Student Name: " << current->student->name << endl;

		current = current->next;
	} while (current != head);
}

