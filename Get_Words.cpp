//
// Created by andrefmrocha on 21-03-2018.
//
#include "Get_Words.h"
using namespace std;
vector<string> get_Words(ifstream infile);
// Gets the Dictionary
vector<string> get_Dic(string filename)
{
    ifstream infile(filename);
    while (!infile.is_open())
    {
        infile.open(filename);
    }

    // Sorts all information into single vector
    vector<string> word_Vec;
    string saving_String;
    while(getline(infile, saving_String))
    {
        if(saving_String == "")
        {
            continue;
        }
        bool flag = true;           //check if there's an invalid character
        for (int i = 0; i < saving_String.length(); ++i)
        {
            char character = saving_String[i];
            if (character < 'A' || character >'Z')
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            word_Vec.push_back(saving_String);
        }
    }
    return word_Vec;
}


