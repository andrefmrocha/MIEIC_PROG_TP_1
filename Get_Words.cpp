//
// Created by andrefmrocha on 21-03-2018.
//
#include <strings.h>
#include "Get_Words.h"
using namespace std;
vector<string> get_Words(ifstream infile);
// Gets the Dictionary and saves into vector
vector<string> get_Dic(string filename)
{
    cout << "Opening " << filename << "..." << endl;
    ifstream infile(filename);
    while (!infile.is_open())
    {
        infile.open(filename);
    }

    // Sorts all information into single vector
    vector<string> word_Vec;
    string saving_String;
    int i = 0;
    char current_character = 'A';
    cout << "Starting collection of all words ... " << endl;
    cout << current_character << endl;
    while(getline(infile, saving_String))
    {
        if(word_Vec.size() % 100)
        {
            cout << '.';
        }
        if(saving_String.empty() || saving_String == "\n" || saving_String == "\r" || saving_String == " ")
        {
            continue;
        }
        trim_String(saving_String);
        bool flag = true;   //check if there's an invalid character
        bool multWord_flag = false; //check if there's 2+ words in a single line
        for (int i = 0; i < saving_String.size(); ++i)
        {
            char character = saving_String[i];
            if(character == ';')
            {
                multWord_flag = true;
                break;
            }
            else if ((character < 'A' || character >'Z' ) && character != '\n' && character!='\r')
            {
                flag = false;
            }

        }
        if(flag || multWord_flag)
        {
            if(saving_String[0] > current_character)
            {
                current_character++;
                cout << '\n' << current_character << endl;
            }
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
    word_Vec.erase( unique(word_Vec.begin(), word_Vec.end()), word_Vec.end());
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
            if(valid_Word(saving_Word))
            {
                word_Vec.push_back(saving_Word);
            }
            last_index = i + 2;
        }
        if(i == saving_String.size() - 1 && character!=';')
        {
            saving_Word = saving_String.substr(last_index,i+1 - last_index);
            if(valid_Word(saving_Word))
            {
                word_Vec.push_back(saving_Word);
            }
        }
    }
}

void trim_String(string &saving_String)
{
    if(saving_String[0] == ' ') // Check if there's a space at the beggining of the string
    {
        saving_String = saving_String.substr(1,saving_String.size()-1);
    }
    char last_char = saving_String[saving_String.size()-1];
    if(last_char == ' ' || last_char == '\n' || last_char == '\r')
    {
        cout << saving_String[saving_String.size()-1];
        saving_String = saving_String.substr(0,saving_String.size()-1);
    }
}

/*bool compareString(const string a,const string b) //Checks if the name needs to be sorted
{
    return strcasecmp(a.c_str(),b.c_str()) <= 0;
}*/

void quickSort(vector<string> &word_Vec)
{
    sort(word_Vec.begin(), word_Vec.end());
//    qsort(word_Vec, word_Vec.size(), sizeof(string), compareString);
}

void push_Words(vector<string> &word_Vec, string saving_String)
{
    if(!saving_String.empty())
    {
        trim_String(saving_String);
        word_Vec.push_back(saving_String);
    }
}

void remove_Null(vector<string> &word_Vec)
{
    for(int i = 0; i<word_Vec.size(); ++i)
    {
        if(word_Vec[i].empty())
        {
            word_Vec.erase(word_Vec.begin()+i);
            i--;
        }
    }
}

bool valid_Word(string saving_String)
{
    for (int i = 0; i < saving_String.size(); ++i) {
        char character = saving_String[i];
        if ((character < 'A' || character >'Z' ) && character != '\n' && character!='\r')
        {
            return false;
        }

    }
    return true;
}
