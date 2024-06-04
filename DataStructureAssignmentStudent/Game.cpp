/*
#include <iostream>
#include "DiscardedDeck.h"
#include "LinkedList.h"
#include "answered.h"
#include "Reader.h"

using namespace std;

void displayMenu() {
    cout << "1. View and Answer Questions from Unanswered Deck" << endl;
    cout << "2. View and Answer Questions from Discarded Deck" << endl;
    cout << "3. Display Answered Questions" << endl;
    cout << "4. Search Discarded Questions by Keyword" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    LinkedList* unansweredDeck = new LinkedList();
    AnsweredStack* answeredStack = new AnsweredStack();
    DiscardedDeck* discardedDeck = new DiscardedDeck();
    int choice;
    Reader::readQuestionsFromFile(unansweredDeck);
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

    return 0;
}
*/
