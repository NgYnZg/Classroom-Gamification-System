
#include "StudentCLL.h"
#include "TopStudentTree.h"
#include <iostream>
#include "DiscardedDeck.h"
#include "answered.h"
#include "LinkedList.h"
#include "Reader.h"

using namespace std;

void displayMenu() {
    cout << "1. View and Answer Questions from Unanswered Deck" << endl;
    cout << "2. View and Answer Questions from Discarded Deck" << endl;
    cout << "3. Display Answered Questions" << endl;
    cout << "4. Search Discarded Questions by Keyword" << endl;
    cout << "5. Exit" << endl;
}

void displayHome() {
    cout << "1. Lecturer" << endl;
    cout << "2. Student" << endl;
    cout << "3. Exit" << endl;
}

void displayLectureHome() {
    cout << "1. Register Student" << endl;
    cout << "2. Leaderboard" << endl;
    cout << "3. Winner Chart" << endl;
    cout << "4. Exit" << endl;
}
void displayRegisteredStudent() {
    cout << "1. Register More Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. Exit" << endl;
}

int main() {

    StudentCLL* participantList = new StudentCLL("Participants");

    // select role
    // 1. lecturer
    // 1.1 register student -> (register more, start the game)
    // 1.2 start the game
    // 1.2.1 loop through students
    // 
    // 1.3 leaderboard
    // 1.4 winner chart
    // 
    // 2. student (name)
    // 2.1 show in winner
    // 2.2 show answered results (Optional)

    while (exit) {
        bool run = true;
        int choice;
        displayHome();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:

        case 2:

        case 3:
            run = false;
            break;
        default:
            cout << "Invalid input!!" << endl;
            break;
        }
    }
}

void lecturerHomeInterface() {
    bool run = true;
    while (run){
        int choice;
        displayLectureHome();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:

        case 2:

        case 3:
            run = false;
            break;
        default:
            cout << "Invalid input!!" << endl;
            break;
        }
    }
}

void studentHomeInterface() {
    bool run = true;
    while (run) {
        cout << "Enter student name: ";
        string student;
        getline(cin, student);
        student= Reader::toLowercase(student);

        cin.ignore();

    } 
}

CLLnode* registerStudentInterface(CLLnode* studentList) {
    bool run = true;
    while(run) {

        cout << "Enter student name: ";
        string student;
        getline(cin, student);
        student = Reader::toLowercase(student);
        
        displayRegisteredStudent();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1: // Register more student

        case 2: // Delete student

        case 3: // Start the game

        case 4: // Exit
            run = false;
            break;
        default:
            cout << "Invalid input!!" << endl;
            break;
        }
        
    }
}

//Inserting Circular Linked List into Binary Search Tree
void insertCLLintoBST() {

}


void leaderboard(TreeNode* fullBST) {
    
}

void winnerChart(TreeNode* winnerBST) {

}

//Search for student result ( in winner chart?, total score, question answered)
void studentResult() {
    
}












void gameInterface(){
    //Initializing structures
    LinkedList* unansweredDeck = new LinkedList();
    AnsweredStack* answeredStack = new AnsweredStack();
    DiscardedDeck* discardedDeck = new DiscardedDeck();
    Reader::readQuestionsFromFile(unansweredDeck);

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: {
            Question1* q = unansweredDeck->displayAndRemoveFirstQuestion();
            cout << "Do you want to answer this question? (yes/no): ";
            string answerChoice;
            getline(cin, answerChoice);
            answerChoice = Reader::toLowercase(answerChoice);
            if (answerChoice == "yes" || answerChoice == "y") {

                cout << "Enter your student ID: ";
                int studentid;
                cin >> studentid;
                cin.ignore();

                cout << "Enter your answer: ";
                string studentanswer;
                getline(cin, studentanswer);


                Question3* q2 = new Question3(q->question, q->answer, q->questionid, q->questionscore);
                recordAnswer(q2, studentid, studentanswer, false);
                answeredStack->push(q2);
            }
            else if (answerChoice == "no" || answerChoice == "n") {
                // Discard the question
                Question2 discardedCard(q->question, true, 0, q->questionid, q->answer, q->questionscore);
                discardedDeck->discardCard(discardedCard);
            }
            break;
        }
        case 2: {
            discardedDeck->sortScore();
            discardedDeck->displayDiscardedCards();
            cout << "Enter the index of the question to answer: ";
            int index;
            cin >> index;
            cin.ignore();
            try {
                Question2 cardToAnswer = discardedDeck->selectDiscardedCard(index);
                cout << "Enter your student ID: ";
                int studentid;
                cin >> studentid;
                cin.ignore();
                cout << "Enter your answer: ";
                string studentanswer;
                getline(cin, studentanswer);
                Question3 q(cardToAnswer.question, cardToAnswer.answer, cardToAnswer.questionid, cardToAnswer.questionscore);
                recordAnswer(&q, studentid, studentanswer, true);
                answeredStack->push(&q);
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            // Display Answered Questions
            answeredStack->display();
            break;
        }
        case 4: {
            // Search Discarded Questions by Keyword
            cout << "Enter keyword to search: ";
            string keyword;
            cin.ignore();
            getline(cin, keyword);
            discardedDeck->searchKeyword(keyword);
            break;
        }
        case 5:
            cout << "Exiting the game..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);
}



/*

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

	
//Printing the first question id of the questions answered by the student
cout << student->student->answered->peek()->questionid << endl;
//Move the list into the next one
student->student->answered->dequeue();
//Print the second question id
cout << student->student->answered->peek()->questionid << endl;
	


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
