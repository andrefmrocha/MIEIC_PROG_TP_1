//
// Created by andre on 11/04/2018.
//

#include "Prog_2_Andre.h"
#include "Program_2.h"
using namespace std;

int main()
{   ifstream file_words;
    vector<string> fileVec;
    string filename;
    cout << "Please write the name of the dictionary file: ";
    cin >> filename;
    OpenToVec(file_words, fileVec, filename);
    vector<letterCounter> lettersVec = ConvertToStruct(fileVec);
    string anotOp;
    do
    {
        system("cls");
		cout << "Welcome to Play With Words! Please choose which function would like to use: " << endl << endl;
		cout << "1) Check for a word in the list" << endl;
        cout << "2) Try to guess a word with its letter" << endl;
        cout << "3) Get all words that can be built with a given set of letters" << endl;
        cout << "4) Give out a random set of letters for you to try and make words with" << endl;
		cout << "5) Wildcard function" << endl << endl;
        int num;
        cin >> num;
        switch (num)
        {
            case 1:
                IsWordInList(fileVec);
                break;
            case 2:
                guessWord(fileVec,lettersVec);
                break;
            case 3:
                GiveWords(fileVec, lettersVec);
                break;
            case 4:
                setofLetters(fileVec, lettersVec);
                break;
            case 5:
                wildcardGame(fileVec);
                break;
            default:
                cout << "Function not defined! ";
        }
        cout << endl << "Would you like to continue(Y/N)" << endl;
        cin >> anotOp;
        UpperInput(anotOp);
        while( anotOp != "Y" && anotOp != "N")
        {
            cout << "Invalid response, please type again :" << endl;
            cin >> anotOp;
            UpperInput(anotOp);
        }
    }while(anotOp == "Y");
}