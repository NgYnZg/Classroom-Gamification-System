#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_Reader.h"
#include "G16_TP068471_TP071864_TP068701_TP066218_TP071960_LinkedList.h"
#include <sstream>
#include <fstream>
#include <iostream>

string Reader::toUppercase(string str) {
    string result = "";

    for (char ch : str) {
        // Convert each character to lowercase using tolower 
        result += toupper(ch);
    }

    return result;
}


/// <summary>
/// Splitting the input string and store inside an array
/// </summary>
/// <param name="strArray"> : Pointer of string array</param>
/// <param name="line"> : String of the line</param>
/// <param name="separator"> : Character of the separator </param>
string* Reader::splitString(string* strArray, string line, char separator, int arrSize) {
    string part;
    int partIndex = 0;
    stringstream ss(line);
    // Split the line by semicolons
    while (getline(ss, part, separator) && partIndex < arrSize) {
        strArray[partIndex++] = part;
    }
    return strArray;
}

void Reader::readQuestionsFromFile(LinkedList* list) {
    ifstream file("DSTRquestion.txt"); // Use the provided filename parameter
    if (!file.is_open()) {
        cout << "Failed to open file: " << endl;
        return;
    }

    string line;
    int questionNumber = 1; // Assuming questions start from 1

    while (getline(file, line)) {
        const int strSize = 4, qSize = 5;
        string* parts, *questionParts; // Assuming exactly 4 parts: ID, Question, Answer, Score
        string strArray[strSize], qArray[qSize];
        // Split the line by semicolons
        parts = splitString(strArray, line, ';', strSize);
        questionParts = splitString(qArray, parts[1], '#', qSize);
        // Ensure the line has exactly the required number of parts
        if (true) {
            int questionid = stoi(parts[0]); // Assuming ID is the first part
            string question = questionParts[0] + '\n' + questionParts[1] + '\n' + questionParts[2] + '\n' + questionParts[3] + '\n' + questionParts[4]; // Assuming Question content is the second part
            string answer = parts[2]; // Assuming Answer is the third part
            int questionscore = stoi(parts[3]); // Assuming Score is the fourth part

            // Create a QuestionStruct object and add it to the linked list
            Question1* q = new Question1(questionid, question, answer, questionscore);
            list->addQuestion(q);
        }
        else
            cout << "Question " << parts[0] << ": " << parts[1] << " is in incorrect format" << endl;
    }
}