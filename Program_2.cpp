//
// Created by joaom on 23-03-2018.
//
#include "Program_2.h"

using namespace std;

// Open file e go through each line extrating it to the vector with push_back
void OpenToVec(ifstream &file_words, vector<string> &fileVec) {
    try {
        file_words.open("Ex_P2.txt");
    }
    catch (const exception &) {
        cerr << "Input file opening failed.\n";   // error message if opening file fails
        exit(1);
    }
    string line;
    while (getline(file_words, line)) {
        fileVec.push_back(line);
    }
    file_words.close();
}

//Test function to verify that the created vector has all the words from the list.
void testingOTV(const vector<string> &fileVec) {
    for (int i = 0; i < fileVec.size(); i++) {
        cout << fileVec[i] << endl;
    }
}

// Binary search algorithm to find the input string in the word list, saved in a vector.
/*
 bool BiSearch(const vector<string> &fileVec, const string &target) {
    int min = 0;
    int max = fileVec.size() - 1;
    bool found =
    int avg;
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
*/



void UpperInput(string &input) {
    for (int i = 0; i < input.length(); i++) {
        input[i] = _toupper(input[i]);
    }
}

// Asks the user for the input string, searches it and check if its valid or not.
void IsWordInList(const vector<string> &fileVec) {
    string target;
    cout << "What is the word you want to search? (ALL CAPS ONLY) " << endl;
    cin >> target;
    UpperInput(target);
    bool valOp;
    valOp = binary_search(fileVec.begin(), fileVec.end(),
                          target);    // Using the binary search algorithm from std library
    if (valOp) {                                                      // to ease the program building
        cout << "The word is valid." << endl;
    } else {
        cout << "The word is invalid. " << endl;
    }
}

//function that searches word list for words with size N and selects them into a new vector to make search quicker
vector<string> WordsNLetters(const vector<string> &fileVec, int Nsize) {
    vector<string> valWords;
    for (int i = 0; i < fileVec.size(); i++) {
        if (fileVec[i].length() == Nsize) {
            valWords.push_back(fileVec[i]);
        }
    }
    return valWords;
}


//function that searches thorugh all valid words checking if they have the same words as in the set of letters, if so, they are added to a vector that will contain them
vector<string> SearchWords(const vector<string> &valWords, const vector<string> &setLetters) {
    vector<string> Poswords;
    for (int i = 0; i < valWords.size(); i++) {
        bool flag = true;
        for (int i2 = 0; i2 < setLetters.size(); i2++) {
            if (valWords[i].find_first_of(setLetters[i2]) ==
                string::npos) {     //this condition checks if every letter of the user given set belongs to a certain word
                flag = false;                                                    //if not, the flag is put false and the cycle breaks, proceeding to the next word
                break;
            }
        }
        if (flag) {
            Poswords.push_back(valWords[i]);
        }

    }
    return Poswords;
}

// function that asks the user for a set of letters and stores them into a vector, proceeding to search for valid words that contain the same given letters.
void GiveWords(const vector<string> &fileVec) {
    vector<string> setLetters;
    cout << "Which letters do want to use to form words? (CTRL+Z to stop) ";
    string chr;
    UpperInput(chr);
    while (!cin.eof()) {                                  //a cycle to carry in every valid char (as string) input by user
        cin >> chr;                                        // and store it in a vector that holds the set of N letters
        setLetters.push_back(chr);
    }
    int Nsize = setLetters.size();
    vector<string> valWords = WordsNLetters(fileVec,
                                            Nsize);    //reduces the number of words to search for, to those with the same length as the number of letters given
    vector<string> PosWords = SearchWords(valWords,
                                          setLetters); // calls the function that will return the vector of valid words
    if (PosWords.empty()) {
        cout << "There is no match for the given letters."
             << endl;    // if no words are found with the given letters, a error message shall appear on the screen
    } else {
        cout << "The list of valid words is: "
             << endl;                  // the list of valid words are written into the screen, already ordered
        for (int i = 0; i < PosWords.size(); i++) {
            cout << PosWords[i] << endl;
        }
    }
}

//This function selects a word randomly from the list, scrambles it and return a vector of the word to be guessed and the scrambled one
vector<string> randomWord(const vector<string> &fileVec) {
    srand((time(NULL)));
    int wordI = rand() % fileVec.size();   // randomly selects an index from the file vector
    string word = fileVec[wordI];          // stores the selected word
    string rword = fileVec[wordI];         // ANDRÉ :creates a copy of the word
    next_permutation(rword.begin(), rword.end());     // scrambles the chars in the vector
    vector<string> words;                              //returns the right word and the scrambled word
    words.push_back(word);
    words.push_back(rword);
    return words;
}

//This function interacts with user, giving in a scrambled word to guess with 3 tries, if not successful, a 'end of game' message shall appear
void guessWord(const vector<string> &fileVec) {
    vector<string> words = randomWord(fileVec);
    string rword = words[1];                          // gets a random word and its scrambled copy from the randomWord function
    string word = words[0];             // ANDRÉ: Words were being stored the other way around
    string guess;
    bool flag = false;           //this flag will set if the user won the game or not
    cout << "The word to guess is " << rword << ". What is your guess? ";
    for (int i = 3; i >
                    0; i--) {                   //ANDRÉ: Suggestion - Run the word through a function to make it all uppercases, in case it isn't
        cin >> guess;
        UpperInput(guess);
        if (guess == word) {                                                //the user has 3 tries to guess the word
            cout << "You chose wisely. Congratulations!" << endl;           //and each interaction has its own message
            flag = true;                                                    // either if guesses right or wrong
            break;
        } else if (i == 1) {
            break;
        } else {
            cout << "You chose poorly. Try again." << endl;
        }
    }
    if (!flag) {                                                   // if all tries have been used and the user didn't guess
        cout << "You lose. Better luck next time..." << endl;      // the game ends with a positive message :')
    }
}


vector<int> NumberOcorrencesLetter(const vector<string> &fileVec) {
    vector<int> NOL;
    NOL.resize(26);
    string elem;
    char elem2;
    int x;
    for (int i = 0; i < fileVec.size(); i++) {
        elem = fileVec[i];
        for (int i2 = 0; i2 < elem.length(); i2++) {
            elem2 = elem[i2];
            x = atoi(reinterpret_cast<const char *>(elem2))-65;
            NOL[x] = NOL[x]++;
        }
    }
    return NOL;
}


int main() {
    ifstream file_words;
    vector<string> fileVec;
    OpenToVec(file_words, fileVec);
    /* testingOTV(fileVec);
    IsWordInList(fileVec);
    GiveWords(fileVec);
    guessWord(fileVec);*/
    vector<int> test1 = NumberOcorrencesLetter(fileVec);
    for (int i = 0; i < test1.size(); i++) {
        cout << test1[i] << " ";
    }
    cout << endl;
    return 0;
}

