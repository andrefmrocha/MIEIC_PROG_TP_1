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
void push2Plus_Words(vector<string> &word_Vec, string saving_String, char &current_character);
void trim_String(string &saving_String);
void quickSort(vector<string> &word_Vec);
void remove_Null(vector<string> &word_Vec);
void pushWords(vector<string> &word_Vec, string saving_String);
bool valid_Word(string saving_String);
void newChar(char next_char, char &current_char);
#endif //TRABALHO_PRATICO_GET_WORDS_H
