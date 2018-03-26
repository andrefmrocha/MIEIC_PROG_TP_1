//
// Created by andrefmrocha on 21-03-2018.
//
#include "Get_Words.h"
using namespace std;
// Gets the Dictionary
ifstream get_Dic(string filename)
{
    ifstream infile(filename);
    while (!infile.is_open())
    {
        infile.open(filename);
    }
    return infile;
}

// Sorts all information into single vector
vector<string> get_Words(ifstream infile)
{
    vector<string> word_Vec;
    string saving_String;
    while(getline(infile, saving_String))
    {
        for (int i = 0; i < saving_String.length(); ++i)
        {
            char character = saving_String[i];
            if (character >= 'A' && character <='Z')
            {
                word_Vec.push_back(saving_String);
            }
        }
    }
}