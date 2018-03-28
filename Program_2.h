//
// Created by joaom on 23-03-2018.
//

#ifndef CRL_PROGRAM_2_H
#define CRL_PROGRAM_2_H
#include "Program_2.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void OpenToVec(ifstream &file_words, vector <string> &fileVec);
void testingOTV (vector <string> fileVec);
bool BiSearch(vector<string> fileVec, string target);
void IsWordInList(vector<string> fileVec);

#endif //CRL_PROGRAM_2_H
