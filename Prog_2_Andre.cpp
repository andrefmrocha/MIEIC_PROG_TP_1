//
// Created by andrefmrocha on 02-04-2018.
//

#include "Prog_2_Andre.h"


// Function to find words written with those letters
letterCounter wordsLetters(const string &word)
{
    letterCounter letters;
    for(int i = 0; i < word.size(); i++)
    {
        char character = word[i];
        switch (character)
        {
            case 'A':
                letters.a++;
                break;
            case 'B':
                letters.b++;
                break;
            case 'C':
                letters.c++;
                break;
            case 'D':
                letters.d++;
                break;
            case 'E':
                letters.e++;
                break;
            case 'F':
                letters.f++;
                break;
            case 'G':
                letters.g++;
                break;
            case 'H':
                letters.h++;
                break;
            case 'I':
                letters.i++;
                break;
            case 'J':
                letters.j++;
                break;
            case 'K':
                letters.k++;
                break;
            case 'L':
                letters.l++;
                break;
            case 'M':
                letters.m++;
                break;
            case 'N':
                letters.n++;
                break;
            case 'O':
                letters.o++;
                break;
            case 'P':
                letters.p++;
                break;
            case 'Q':
                letters.q++;
                break;
            case 'R':
                letters.r++;
                break;
            case 'S':
                letters.s++;
                break;
            case 'T':
                letters.t++;
                break;
            case 'U':
                letters.u++;
                break;
            case 'V':
                letters.v++;
                break;
            case 'W':
                letters.w++;
                break;
            case 'X':
                letters.x++;
                break;
            case 'Y':
                letters.y++;
                break;
            case 'Z':
                letters.z++;
                break;
        }
    }
    return letters;
}

// WildcardMatch function under the appendixes of the project
bool wildcardMatch(const char *str, const char *strWild)
{
// We have a special case where string is empty ("") and the mask is "*".
// We need to handle this too. So we can't test on !*str here.
// The loop breaks when the match string is exhausted.
    while (*strWild)
    {
// Single wildcard character
        if (*strWild== '?')
        {
// Matches any character except empty string
            if (!*str)
                return false;
// OK next
            ++str;
            ++strWild;
        }
        else if (*strWild== '*')
        {
// Need to do some tricks.
// 1. The wildcard * is ignored.
// So just an empty string matches. This is done by recursion.
// Because we eat one character from the match string,
// the recursion will stop.
            if (wildcardMatch(str,strWild+1))
// we have a match and the * replaces no other character
                return true;
// 2. Chance we eat the next character and try it again,
// with a wildcard * match. This is done by recursion.
// Because we eat one character from the string,
// the recursion will stop.
            if (*str && wildcardMatch(str+1,strWild))
                return true;
// Nothing worked with this wildcard.
            return false;
        }
        else
        {
// Standard compare of 2 chars. Note that *str might be 0 here,
// but then we never get a match on *strWild
// that has always a value while inside this loop.
            if (toupper(*str++)!=toupper(*strWild++))
                return false;
        }
    }
// Have a match? Only if both are at the end...
    return !*str && !*strWild;
}

//Wildcard Function to make the necessary comparison with the wildMatch
vector<string> possibleWords(const vector<string> &wordVec, const string &wildcardString)
{
    vector<string> possible_Words;
    for(int i = 0; i<wordVec.size(); i++)   //Runs through the vector to find all words that fit the criteria
    {
        if(wildcardMatch(wordVec[i].c_str(), wildcardString.c_str()))
        {
            possible_Words.push_back(wordVec[i]);
        }
    }
    return possible_Words;
}


void wildcardGame(const vector<string> &wordVec) //Function to execute the WildcardGame
{
    string wildcardString;
    cout << "Write your wildcard word: ";
    cin >> wildcardString;
    vector<string> possible_Words = possibleWords(wordVec, wildcardString);
    cout << "The possible words are: " << endl;
    for(int i = 0; i < possible_Words.size(); i++)
    {
        cout << i + 1 << " - " <<  possible_Words[i] << endl;
    }
}

bool invalidWord(const string &word) //Checks if user inputted word is Invalid
{                                    //To be used before any user input, to prevent it from failing automatically
    for(int i = 0; i<word.size(); i++)
    {
        char character = word[i];
        if(character < 'A' || character > 'Z')
            return true;
    }
    return false;
}
