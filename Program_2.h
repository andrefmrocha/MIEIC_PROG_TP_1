//
// Created by joaom on 23-03-2018.
//

#ifndef CRL_PROGRAM_2_H
#define CRL_PROGRAM_2_H
#include "Program_2.h"
#include "Prog_2_Andre.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <numeric>
#include <locale>
#include <sstream>
#include <cstring>
using namespace std;

void OpenToVec(ifstream &file_words, vector<string> &fileVec);
void testingOTV(const vector<string> &fileVec);
bool BiSearch(const vector<string> &fileVec, const string &target);
void IsWordInList(const vector<string> &fileVec);
void UpperInput (string &input);
vector<string> WordsNLetters(const vector<string> &fileVec, int Nsize);
vector<string> SearchWords(const vector<string> &valWords, const vector<string> &setLetters);
vector<int> IndexValWords(vector<struct letterCounter> CTS, struct letterCounter wordletters);
vector<struct letterCounter> ConvertToStruct(const vector<string> &fileVec);
void PrintValWords(const vector<string> &fileVec, vector<int> indexval);    
void GiveWords(const vector<string> &fileVec);
vector<string> randomWord(const vector<string> &fileVec);
void guessWord(const vector<string> &fileVec);
int biggerword(const vector<string> &fileVec);
vector<double> frequencyLetters(const vector<struct letterCounter> &letC);
string randsetletters (const vector <struct letterCounter > &letC, const vector<string> &fileVec);
void setofLetters(const vector<string> &fileVec);
#endif //CRL_PROGRAM_2_H
