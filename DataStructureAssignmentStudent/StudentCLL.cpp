#include "StudentCLL.h";
#include "StudentAnswered.h";
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

/// <summary>
/// Creating a new Circular Linked List (CLL) node based on the student's name and inserting the node into the list
/// </summary>
/// <param name="studentname"></param>
void StudentCLL::insertHead(string studentname) {
	//Creating new node
	CLLnode* newNode = createNewNode(this->size, studentname);
	size++;

	//1. if no nodes in the CLL
	if (this->head == NULL) {
		this->head = this->tail = newNode;
		return;
	}
	//2. if node exist in the CLL	steps: point newnode.next to head -> make newnode the new head -> connect tail to the new head
	newNode->next = head;
	head = newNode;
	tail->next = head;
}
/// <summary>
/// Creating a new student based on name and inserting the node into the list
/// </summary>
/// <param name="studentname"></param>
void StudentCLL::insertTail(string studentname) {
	//Creating new node
	CLLnode* newNode = createNewNode(this->size, studentname);
	size++;

	//1. if no nodes in the CLL
	if (this->head == NULL) {
		this->head = this->tail = newNode;
		return;
	}
	//2. if node exist in the CLL	steps: point tail.next to new node -> make newnode the new tail -> connect new tail.next to the head
	tail->next = newNode;
	tail = newNode;
	tail->next = head;
}

/// <summary>
/// Deletion of Circular Linked List (CLL) node based on student id
/// </summary>
/// <param name="studentid"></param>
/// <returns name="deletedStudent"></returns>
CLLnode* StudentCLL::deleteNode(int studentid) {
	CLLnode* prev, * current = head;

	//If list have is empty
	if (head == nullptr) {
		cout << "There is no node to delete!!" << endl;
		return NULL;
	}

	//If head of the list is to be deleted
	if (head->student->studentid == studentid) {
		//If the list only contains one node
		if (head == tail)
		{
			head = tail = nullptr;
			current->next = nullptr;
			size--;
			return current;
		}
		//If the list contains more than one node
		head = head->next;
		tail->next = head;
		current->next = nullptr;
		size--;
		return current;
	}

	//Loop through the list to find the matched student node
	prev = current;
	current = current->next;
	while (current != head) {
		//Steps: search through the node to find the node with matched studentid
		if (current->student->studentid == studentid) {
			prev->next = current->next;
			current->next = nullptr;
			size--;
			return current;
		}
		//Incrementing node index
		prev = current;
		current = current->next;
	}

	cout << "Student id does not exist!!" << endl;
	return new CLLnode;
}

/// <summary>
/// Deletion of Circular Linked List (CLL) node based on student name
/// </summary>
/// <param name="studentid"></param>
/// <returns name="deletedStudent"></returns>
CLLnode* StudentCLL::deleteNode(string name) {
	CLLnode* prev, * current = head;

	//If list have is empty
	if (head == nullptr) {
		cout << "There is no node to delete!!" << endl;
		return new CLLnode;
	}

	//If head of the list is to be deleted
	if (head->student->name == name) {
		//If the list only contains one node
		if (head == tail)
		{
			head = tail = nullptr;
			current->next = nullptr;
			size--;
			return current;
		}
		//If the list contains more than one node
		head = head->next;
		tail->next = head;
		current->next = nullptr;
		size--;
		return current;
	}

	//Loop through the list to find the matched student node
	prev = current;
	current = current->next;
	while (current != head) {
		//Steps: search through the node to find the node with matched studentid
		if (current->student->name == name) {
			prev->next = current->next;
			current->next = nullptr;
			size--;
			return current;
		}
		//Incrementing node index
		prev = current;
		current = current->next;
	}

	cout << "Student name does not exist!!" << endl;
	return new CLLnode;
}

/// <summary>
/// Searching Circular Linked List (CLL) node using studentid
/// </summary>
/// <param name="studentid"></param>
/// <returns>Returns a CLLnode that holds student node </returns>
CLLnode* StudentCLL::search(int studentid) {
	CLLnode* prev, * current = head;

	if (head->student->studentid == studentid) {
		return head;
	}

	//Loop through the list to find the matched student node
	prev = current;
	current = current->next;
	while (current != head) {
		//Steps: search through the node to find the node with matched studentid
		if (current->student->studentid == studentid) {
			prev->next = current->next;
			return current;
		}
		//Incrementing node index
		prev = current;
		current = current->next;
	}
	cout << "Student id does not exist!!" << endl;
	return new CLLnode();
}


/// <summary>
/// Searching a Circular Linked List (CLL) node using name
/// </summary>
/// <param name="name"> Name of the Student</param>
/// <returns> Returns a CLLnode that holds student node </returns>
CLLnode* StudentCLL::search(string name) {
	CLLnode* prev, * current;

	if (head->student->name == name) {
		return head;
	}
	//Loop through the list to find the matched student node
	prev = head;
	current = head->next;
	while (current != head) {
		//Steps: search through the node to find the node with matched studentid
		if (current->student->name == name) {
			return current;
		}
		//Incrementing node index
		prev = current;
		current = current->next;
	}
	cout << "Student name does not exist!!" << endl;
	return new CLLnode;
}

/// <summary>
/// Adding totalScore of the student that has answered or discared the question,
/// enqueue the question id into the answered queue of the student.
/// </summary>
/// <param name="current"> Current node of answering student </param>
/// <param name="score"> Scored points</param>
void StudentCLL::score(CLLnode* current, int questionid, double score) {
	cout << "Student " << current->student->name << " previous total score " << current->student->totalScore << endl;
	current->student->totalScore += score;
	current->student->answered->enqueue(questionid);
	cout << "Student " << current->student->name << " after total score " << current->student->totalScore << endl;
}


/// <summary>
/// Displaying all students' name and total score
/// </summary>
void StudentCLL::display() {
	CLLnode* current = head;

	cout << "Students: " << endl;
	do {
		cout << "Student Name: " << current->student->name << endl;
		cout << "Total Score: " << current->student->totalScore << endl;

		current = current->next;
	} while (current != head);
}

