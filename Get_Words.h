//
// Created by andrefmrocha on 21-03-2018.
//

#ifndef TRABALHO_PRATICO_GET_WORDS_H
#define TRABALHO_PRATICO_GET_WORDS_H
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string>  get_Dic(string filename);
void remove_Duplicates(vector<string> &word_Vec);
#endif //TRABALHO_PRATICO_GET_WORDS_H
