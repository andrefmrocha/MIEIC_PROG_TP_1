//
// Created by andrefmrocha on 21-03-2018.
//
#include "Get_Words.h"
using namespace std;
// Gets the Dictionary and saves into vector
vector<string> get_Dic(string filename)
{
    cout << "Opening " << filename << "..." << endl;
    ifstream infile(filename);      //Opens the filename
    while (!infile.is_open())       //Checks if the input name does in fact exist
    {
        cout << "File not found! Please write the name of the file again.";
        infile.open(filename);
    }
    vector<string> word_Vec;            // word_Vec : stores all valid words
    string saving_String;
    unsigned char current_character = 'A';       // Initiliazes the characters for the screen output
    cout << "Starting collection of all words from file ... " << filename << endl;
    cout << current_character << endl;
    while(getline(infile, saving_String))
    {
        if(word_Vec.size() % 100)           //check if another dot on screen is needed
        {
            cout << '.';
        }
        if(saving_String.empty() || saving_String == "\n" || saving_String == "\r" || saving_String == " " || saving_String == "")
        {
            continue;       //checks for a useless line to go through immediately
        }
        trim_String(saving_String);
        bool flag = true;   //check if there's an invalid character
        bool multWord_flag = false; //check if there's 2+ words in a single line
        for (int i = 0; i < saving_String.size(); ++i)
        {
            unsigned char character = saving_String[i];
            if(character == ';')            //checks if there's over one word in a line
            {
                multWord_flag = true;
                break;
            }
            else if ((character < 'A' || character >'Z' ) && character != '\n' && character!='\r')
            {
                flag = false;           //checks for the valid characters on a line
            }

        }
        if(flag || multWord_flag )
        {
            if(multWord_flag)
            {
                push2Plus_Words(word_Vec, saving_String, current_character); // function for 2+ words
            }
            else if(flag)
            {
                newChar(saving_String[0], current_character); //checks if it's needed to change the displayed character
                word_Vec.push_back(saving_String);
            }
        }

    }
    return word_Vec;
}



// Uses the fact that the vector is ordered to erase by using the unique algorithm
void remove_Duplicates(vector<string> &word_Vec)
{
    cout << "Removing duplicate words ..." << endl;
    word_Vec.erase( unique(word_Vec.begin(), word_Vec.end()), word_Vec.end());
    cout << "Number of non-duplicate words = " << word_Vec.size() << endl;
}

void push2Plus_Words(vector<string> &word_Vec, string saving_String, unsigned char &current_character)
{
    int last_index = 0;            // Saves the index of the last pushed word
    string saving_Word;
    for(int i = 0; i<saving_String.size(); i++)
    {
        unsigned char character = saving_String[i];
        if(character == ';')
        {
            saving_Word = saving_String.substr(last_index, i-last_index);   //Forms the substring to save the word
            if(saving_Word.empty()) //Checks for a useless string
            {
                break;
            }
            trim_String(saving_Word); //Trims the string before pushing it to the vector
            if(valid_Word(saving_Word))
            {
                word_Vec.push_back(saving_Word);
            }
            last_index = i + 2;
        }
        if(i == saving_String.size() - 1 && character!=';') //Checks if it's the last word of the line
        {
            saving_Word = saving_String.substr(last_index,i+1 - last_index);
            if(saving_Word.empty())
            {
                break;
            }
            trim_String(saving_String);
            if(valid_Word(saving_Word))
            {
                word_Vec.push_back(saving_Word);
            }
        }
    }
}

void trim_String(string &saving_String) {
    //Removes any sort of useless character from our string (more common to happen in g++)
    const auto sBegin = saving_String.find_first_not_of(" \t\n\v\f\r");
    const auto sEnd = saving_String.find_last_not_of(" \t\n\v\f\r");
    const auto range = sEnd - sBegin;

    saving_String = saving_String.substr(sBegin, range + 1);
}

void quickSort(vector<string> &word_Vec)        //Uses the quicksort algorithm to sort the vector
{
    cout.flush();
    cout << "Sorting words ... " << endl;
    sort(word_Vec.begin(), word_Vec.end());
}

void remove_Null(vector<string> &word_Vec)      //Removes any null strings on vector created by the duplicates
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

bool valid_Word(string saving_String)       //Checks if a word is valid(needed to be done separatedly for more
{                                           //than one situation
    for (int i = 0; i < saving_String.size(); ++i) {
        unsigned char character = saving_String[i];
        if ((character < 'A' || character >'Z' ) && character != '\n' && character!='\r')
        {
            return false;
        }

    }
    return true;
}

void newChar(unsigned char next_char, unsigned char &current_char)    // Checks it's needed to change the character on screen
{
    if(next_char > current_char && next_char >= 'A' && next_char <='Z')
    {
        current_char++;
        cout << '\n' << current_char << endl;
    }
}
