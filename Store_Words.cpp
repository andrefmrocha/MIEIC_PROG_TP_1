//
// Created by andrefmrocha on 30-03-2018.
//

#include "Store_Words.h"
using namespace std;

void store_Words(vector<string> word_Vec)
{
    ofstream outfile("Words.txt");
    for(int i = 0; i<word_Vec.size(); i++)
    {
        outfile << word_Vec[i] << '\n';
    }
}
