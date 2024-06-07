
#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_StudentCLL.h"
#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_TopStudentTree.h"
#include <iostream>
#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_DiscardedDeck.h"
#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960__answered.h"
#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_LinkedList.h"
#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_Reader.h"
#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_Search.h"




void displayMenu() {
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1. View and Answer Questions from Unanswered Deck" << endl;
    cout << "2. View and Answer Questions from Discarded Deck" << endl;
    cout << "3. Display Answered Questions" << endl;
    cout << "4. Search Discarded Questions by Keyword" << endl;
}


void displayHome() {
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1. Lecturer" << endl;
    cout << "2. Student" << endl;
    cout << "3. Exit System" << endl;
}

void displayLectureHome() {
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1. Register Student" << endl;
    cout << "2. Display Students" << endl;
    cout << "3. Start the game" << endl;
    cout << "4. Leaderboard" << endl;
    cout << "5. Winner Chart" << endl;
    cout << "6. Exit" << endl;
}
void displayRegisteredStudentOption() {
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1. Register More Student" << endl;
    cout << "2. Delete Last Created Student" << endl;
    cout << "3. Back" << endl;
}



Search* gameInterface(StudentCLL* participantList) {
    //Initializing round number
    int round = 0;
    //Initializing structures
    LinkedList* unansweredDeck = new LinkedList();
    AnsweredStack* answeredStack = new AnsweredStack();
    DiscardedDeck* discardedDeck = new DiscardedDeck();
    Reader::readQuestionsFromFile(unansweredDeck);
    CLLnode* currentStudent = participantList->getHead();
    
    while (round < 3 && unansweredDeck->peek() != NULL){
        int studentid = currentStudent->student->studentid;
        int choice;

        displayMenu();
        cout << "Student " << currentStudent->student->name << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: {
            Question1* q = unansweredDeck->displayAndRemoveFirstQuestion();
            string answerChoice;
            do{
                cout << "do you want to answer this question? (yes/no): ";
                getline(cin, answerChoice);
                answerChoice = Reader::toUppercase(answerChoice);
            } while(!(answerChoice == "YES" || answerChoice == "Y" || answerChoice == "NO" || answerChoice == "N"));
            if (answerChoice == "YES" || answerChoice == "Y") {
                cout << "Enter your answer: ";
                string studentanswer;
                getline(cin, studentanswer);
                studentanswer = Reader::toUppercase(studentanswer);
                Question3* q2 = new Question3(q->question, q->answer, q->questionid, q->questionscore);
                int scored = recordAnswer(q2, studentid, studentanswer, false);
                answeredStack->push(q2);
                currentStudent->score(q->questionid, scored);
            }
            else if (answerChoice == "NO" || answerChoice == "N") {
                // Discard the question
                Question2* discardedCard = new Question2(q->question, true, 0, q->questionid, q->answer, q->questionscore);
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
                Question2* cardToAnswer = discardedDeck->selectDiscardedCard(index);
                cout << "Enter your answer: ";
                string studentanswer;
                getline(cin, studentanswer);
                Question3* q = new Question3(cardToAnswer->question, cardToAnswer->answer, cardToAnswer->questionid, cardToAnswer->questionscore);

                int scored = recordAnswer(q, studentid, studentanswer, true);
                answeredStack->push(q);
                currentStudent->score(q->questionid, scored);
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
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
      
        currentStudent = currentStudent->next;
        if (currentStudent == participantList->getHead())
            round++;

    }

    cout << "Game ended. " << endl;
    unansweredDeck->~LinkedList();
    Search* search = new Search(answeredStack, participantList);
    return search;
}

//Inserting Circular Linked List into Binary Search Tree
TopStudentTree* insertCLLintoBST(StudentCLL* participationList) {
    CLLnode* current = participationList->getHead();
    TopStudentTree* winnerBST = new TopStudentTree();
    do
    {
        winnerBST->insertNewNode(current->student);
        current = current->next;
    } while (current != participationList->getHead());
    return winnerBST;
}

void displayreverse_inorder(TreeNode* current, Search* search) {

    if (current == NULL)
        return;

    // Traverse right subtree
    displayreverse_inorder(current->right, search);

    search->searchLeaderboardStudent(current->student->studentid);
    // Traverse left subtree
    displayreverse_inorder(current->left, search);

}

void leaderboard(TopStudentTree* winnerBST, Search* searchList) {
    searchList->setTopStudent(winnerBST);
    displayreverse_inorder(winnerBST->getRoot(), searchList);
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(TreeNode* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << "Name: " << root->student->name <<" ( "<< root->student->totalScore <<" )" << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(TreeNode* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

void winnerChart(TopStudentTree* winnerBST) {
    print2D(winnerBST->getRoot());
}

void registerStudentInterface(StudentCLL* participantList) {
    bool run = true, runInner;
    while(run){
        cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter student name: ";
        string studentname;
        getline(cin, studentname);
        studentname = Reader::toUppercase(studentname);
        participantList->insertHead(studentname);
        runInner = true;

        while (runInner) {
            displayRegisteredStudentOption();
            int choice;
            cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice)
            {
            case 1: // Register more student
                runInner = false;
                break;
            case 2: // Delete last created student
                participantList->deleteHead();
                break;
            case 3: // Back
                runInner = false;
                run = false;
                break;
            default:
                cout << "Invalid input!!" << endl;
                break;
            }
        }
    }

}


Search* lecturerHomeInterface() {

    StudentCLL* participantList = new StudentCLL("Participants");
    Search* searchList = new Search();
    bool run = true;
    TopStudentTree* studentBST;
    while (run) {
        int choice;
        displayLectureHome(); //Register student, display students, start the game, leaderboard, winner chart, exit
        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            registerStudentInterface(participantList); //Register more student, delete last created student
            break;
        case 2: // Display students
            participantList->display();
            break;
        case 3:
            searchList = gameInterface(participantList); // Start the game
            break;
        case 4:
            studentBST = insertCLLintoBST(participantList); 
            leaderboard(studentBST, searchList); //leaderboard
            break;
        case 5:
            studentBST = insertCLLintoBST(participantList); 
            winnerChart(studentBST); //winner chart
            break;
        case 6: //exit
            run = false;
            break;
        default:
            cout << "Invalid input!!" << endl;
            break;
        }
    }
    return searchList;
}


void studentHomeInterface(Search* search) {

    cout << "Enter student id: ";
    int studentid;
    cin >> studentid;
    cin.ignore();
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    search->searchStudent(studentid);

    if (search == NULL) {
        int choice = 0;
        while (choice != 1) {
            cout << "Students Not Registered!!" << endl;
            cout << "Enter 1 to Exit";
            cin >> choice;
            cin.ignore();
            cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
        }
        return;
    }
}



int main() {


    // select role
    // 1. lecturer
    // 1.1 register student -> (register more, delete last one)
    // 1.2 start the game
    // 1.2.1 loop through students
    // 
    // 1.3 leaderboard
    // 1.4 winner chart
    // 
    // 2. student (name)
    // 2.1 show in winner
    Search* searchList = new Search();
    bool run = true;
    while (run) {
        int choice;
        displayHome();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1: //Selected Lecture
            searchList = lecturerHomeInterface();
            break;
        case 2: //Selected Student
            studentHomeInterface(searchList);
            break;
        case 3:
            run = false;
            break;
        default:
            cout << "Invalid input!!" << endl;
            break;
        }
    }

    return 0;
}

