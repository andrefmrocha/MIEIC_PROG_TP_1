//
// Created by joaom on 23-03-2018.
//
#include "Program_2.h"

using namespace std;

// Open file e go through each line extrating it to the vector with push_back
void OpenToVec(ifstream &file_words, vector<string> &fileVec) {
    try {
        file_words.open("Ex_P2.txt");
    } catch (const exception&) {
        cerr << "Input file opening failed.\n";   // error message if opening file fails
        exit(1);
    }
    if (file_words.fail()) {
    }
    string line;
    while (getline(file_words, line)) {
        fileVec.push_back(line);
    }
    file_words.close();
}

//Test function to verify that the created vector has all the words from the list.
void testingOTV(vector<string> fileVec) {
    for (int i = 0; i < fileVec.size(); i++) {
        cout << fileVec[i] << endl;
    }
}

// Binary search algorithm to find the input string in the word list, saved in a vector.
bool BiSearch(const vector<string> &fileVec, const string &target) {
    int min = 0;
    int max = fileVec.size() - 1;
    int avg;
    bool found = false;
    while (min <= max) {
        avg = lround((max + min) / 2 );
        if (target == fileVec[avg]) {
            found = true;
            break;
        } else if (fileVec[avg] < target) {
            min = avg++;
        } else {
            max = avg--;
        }
    }
    return found;
}

// Asks the user for the input string, searches it and check if its valid or not.
void IsWordInList(vector<string> fileVec) {
    string target;
    cout << "What is the word you want to search? (ALL CAPS ONLY) " << endl;
    cin >> target;
    bool valOp;
    valOp = BiSearch(fileVec, target);
    if (valOp) {
        cout << "The word is valid." << endl;
    } else {
        cout << "The word is invalid. " << endl;
    }
}

int main() {
    ifstream file_words;
    vector<string> fileVec;
    OpenToVec(file_words, fileVec);
    /* testingOTV(fileVec);*/
    IsWordInList(fileVec);

    return 0;

}