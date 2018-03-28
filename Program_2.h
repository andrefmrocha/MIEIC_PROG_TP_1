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
#include <ctime>
#include <numeric>
using namespace std;

void OpenToVec(ifstream &file_words, vector<string> &fileVec);
void testingOTV(const vector<string> &fileVec);
bool BiSearch(const vector<string> &fileVec, const string &target);
void IsWordInList(const vector<string> &fileVec);
vector<string> WordsNLetters(const vector<string> &fileVec, int Nsize);
vector<string> SearchWords(const vector<string> &valWords, const vector<string> &setLetters);
void GiveWords(const vector<string> &fileVec);

#endif //CRL_PROGRAM_2_H
