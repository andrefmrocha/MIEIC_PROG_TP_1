//
// Created by andrefmrocha on 21-03-2018.
//
#include "Get_Words.h"
using namespace std;
vector<string> get_Words(ifstream infile);
// Gets the Dictionary and saves into vector
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
        if(saving_String == "" || saving_String == "\n" || saving_String == "\r")
        {
            continue;
        }
        bool flag = true;   //check if there's an invalid character
        bool multWord_flag = false; //check if there's 2+ words in a single line
        for (int i = 0; i < saving_String.size(); ++i)
        {
            char character = saving_String[i];
            if ((character < 'A' || character >'Z' ) && character != ';' && character != ' ' && character != '\n' && character!='\r')
            {
                flag = false;
                break;
            }
            if(character == ';')
            {
                multWord_flag = true;
            }

        }
        if(flag)
        {
            trim_String(saving_String);
            if(multWord_flag)
            {
                push2Plus_Words(word_Vec, saving_String); // function for 2+ words
            }
            else
            {
                word_Vec.push_back(saving_String);
            }
        }
    }
    return word_Vec;
}



// Uses the fact that the vector is ordered to erase by using the unique algorithm
void remove_Duplicates(vector<string> &word_Vec)
{
    word_Vec.erase( unique(word_Vec.begin(), word_Vec.end()));
}

void push2Plus_Words(vector<string> &word_Vec, string saving_String)
{
    int last_index = 0;            // Saves the index of the last pushed word
    string saving_Word;
    for(int i = 0; i<saving_String.size(); i++)
    {
        char character = saving_String[i];
        if(character == ';')
        {
            saving_Word = saving_String.substr(last_index, i-last_index);
            word_Vec.push_back(saving_Word);
            last_index = i + 1;
        }
        if(i == saving_String.size() - 1)
        {
            saving_Word = saving_String.substr(last_index,i+1 - last_index);
            word_Vec.push_back(saving_Word);
        }
    }
}

void trim_String(string &saving_String)
{
    if(saving_String[0] == ' ') // Check if there's a space at the beggining of the string
    {
        saving_String = saving_String.substr(1,saving_String.size()-1);
    }
    if(saving_String[saving_String.size()-1] == ' ', '\n', '\r')
    {
        saving_String = saving_String.substr(0,saving_String.size()-1);
    }
}


