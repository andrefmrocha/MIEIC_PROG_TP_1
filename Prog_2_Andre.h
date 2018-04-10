//
// Created by andrefmrocha on 02-04-2018.
//

#ifndef TRABALHO_PRATICO_PROG_2_ANDRE_H
#define TRABALHO_PRATICO_PROG_2_ANDRE_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct letterCounter
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int o = 0;
    int p = 0;
    int q = 0;
    int r = 0;
    int s = 0;
    int t = 0;
    int u = 0;
    int v = 0;
    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;
};
letterCounter wordsLetters(const string &word);
vector<string> possibleWords(const vector<string> &wordVec, const string &wildcardString);
bool wildcardMatch(const char *str, const char *strWild);
void wildcardGame(const vector<string> &wordVec);
bool invalidWord(const string &word);

#endif //TRABALHO_PRATICO_PROG_2_ANDRE_H
