//
// Created by andrefmrocha on 02-04-2018.
//

#include "Prog_2_Andre.h"


// Function to find words written with those letters
letterCounter wordsLetters(string word)
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