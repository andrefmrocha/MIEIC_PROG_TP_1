//
// Created by andrefmrocha on 21-03-2018.
//

#ifndef TRABALHO_PRATICO_GET_WORDS_H
#define TRABALHO_PRATICO_GET_WORDS_H
#include <string>
#include <fstream>
#include <vector>

using namespace std;

ifstream get_dic(string filename);
vector<string> get_Words(ifstream infile);
#endif //TRABALHO_PRATICO_GET_WORDS_H
