//
// Created by joaom on 23-03-2018.
//

#ifndef TP_PROGRAM_2_H
#define TP_PROGRAM_2_H
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

void OpenToVec(ifstream &file_words, vector<string> &fileVec, string filename);
void testingOTV(const vector<string> &fileVec);
bool BiSearch(const vector<string> &fileVec, const string &target);
void IsWordInList(const vector<string> &fileVec);
void UpperInput (string &input);
vector<string> WordsNLetters(const vector<string> &fileVec, int Nsize);
vector<string> SearchWords(const vector<string> &valWords, const vector<string> &setLetters);
vector<int> IndexValWords(vector<letterCounter> lettersVec,letterCounter wordletters);
vector<letterCounter> ConvertToStruct(const vector<string> &fileVec);
void PrintValWords(const vector<string> &fileVec, const vector<int> &indexval);
void GiveWords(const vector<string> &fileVec,const vector<letterCounter> &lettersVec );
vector<string> randomWord(const vector<string> &fileVec);
void guessWord(const vector<string> &fileVec);
int biggerword(const vector<string> &fileVec);
vector<double> frequencyLetters(const vector<letterCounter> &letC);
vector<int> relfreq();
string randsetletters(const vector<letterCounter> &lettersVec, const vector<string> &fileVec) ;
bool rightsetletters (const string &setofLet,const string &attempt);
void setofLetters(const vector<string> &fileVec, const vector<letterCounter> &lettersVec);
#endif //TP_PROGRAM_2_H
