#pragma once
#include"LinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Reader {
public:
    static void readQuestionsFromFile(LinkedList* list);

    static string* splitString(string* strArray, string line, char separator);

    static string toLowercase(string str);
};

