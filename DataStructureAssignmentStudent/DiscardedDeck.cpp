#include "DiscardedDeck.h"
using namespace std;

Question2::Question2(const string& q, bool d, int dsid, int qid, const string& a, int qs) {
    question = q;
    discarded = d;
    discardedstudentid = dsid;
    questionid = qid;
    answer = a;
    questionscore = qs;
}

Node::Node(Question2 c) : card(c), next(nullptr), prev(nullptr) {}

DiscardedDeck::DiscardedDeck() : head(nullptr), tail(nullptr) {}

Node* DiscardedDeck::merge(Node* left, Node* right, const function<bool(const Question2&, const Question2&)>& comp) {
    if (!left) return right;
    if (!right) return left;
    Node* result = nullptr;
    if (comp(left->card, right->card)) {
        result = left;
        result->next = merge(left->next, right, comp);
        result->next->prev = result;
        result->prev = nullptr;
    }
    else {
        result = right;
        result->next = merge(left, right->next, comp);
        result->next->prev = result;
        result->prev = nullptr;
    }
    return result;
}

Node* DiscardedDeck::mergeSort(Node* head, const function<bool(const Question2&, const Question2&)>& comp) {
    if (!head || !head->next) return head;
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secondHalf = slow->next;
    slow->next = nullptr;
    Node* left = mergeSort(head, comp);
    Node* right = mergeSort(secondHalf, comp);
    return merge(left, right, comp);
}

void DiscardedDeck::updateTail() {
    tail = head;
    if (tail) {
        while (tail->next) {
            tail = tail->next;
        }
    }
}

void DiscardedDeck::discardCard(const Question2& card) {
    Node* newNode = new Node(card);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DiscardedDeck::displayDiscardedCards() const {
    Node* current = head;
    int index = 1;
    while (current != nullptr) {
        cout << index << ". " << current->card.question << " (Score: " << current->card.questionscore << ")\n";
        current = current->next;
        index++;
    }
}

Question2 DiscardedDeck::selectDiscardedCard(int index) {
    if (index < 1) {
        throw out_of_range("Invalid index");
    }
    Node* current = head;
    int Index = 1;
    while (current != nullptr && Index < index) {
        current = current->next;
        Index++;
    }
    if (current == nullptr) {
        throw out_of_range("Invalid index");
    }
    Question2 selectedCard = current->card;
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    else {
        head = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    else {
        tail = current->prev;
    }
    delete current;
    return selectedCard;
}

DiscardedDeck::~DiscardedDeck() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void DiscardedDeck::sortScore() {
    head = mergeSort(head, [](const Question2& a, const Question2& b) {
        return a.questionscore > b.questionscore;
        });
    updateTail();
}

void DiscardedDeck::searchKeyword(const string& keyword) const {
    Node* current = head;
    int index = 1;
    bool found = false;
    while (current != nullptr) {
        if (current->card.question.find(keyword) != string::npos ||
            current->card.answer.find(keyword) != string::npos) {
            cout << index << ". " << current->card.question << " (Score: " << current->card.questionscore << ")\n";
            found = true;
        }
        current = current->next;
        index++;
    }
    if (!found) {
        cout << "No cards found with the keyword \"" << keyword << "\".\n";
    }
}
