#pragma once
#include"G16_TP068471_TP071864_TP068701_TP066218_TP071960_LinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Reader {
public:
    static void readQuestionsFromFile(LinkedList* list);

    static string* splitString(string* strArray, string line, char separator, int arrSize);

    static string toUppercase(string str);
};

