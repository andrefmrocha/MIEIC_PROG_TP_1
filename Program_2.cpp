//
// Created by joaom on 23-03-2018.
//
#include "Program_2.h"

using namespace std;

// Open file e go through each line extrating it to the vector with push_back
void OpenToVec(ifstream &file_words, vector<string> &fileVec) {
    try {
        file_words.open("Words.txt");
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

//function that reads words from file and organizes them in a new vector, where each word is organized in a struct with his letters
vector<struct letterCounter> ConvertToStruct(const vector<string> &fileVec) {
    vector<struct letterCounter> CTS;
    for (int i = 0; i < fileVec.size(); i++) {
        letterCounter letword = wordsLetters(fileVec[i]);
        CTS.push_back(letword);
    }
    return CTS;
}

// function that compares the structs of words, to check if they have the same letters and returns the indexes of the valid words to a vector
vector<int> IndexValWords(vector<struct letterCounter> CTS, struct letterCounter wordletters) {
    vector<int> IVW;
    letterCounter *ptr1, *ptr2;
    ptr1 = &wordletters;
    for (int i = 0; i < CTS.size(); i++) {
        ptr2 = &CTS[i];
        if (memcmp(ptr1, ptr2, sizeof(wordletters)) == 0) {
            IVW.push_back(i);
        }
    }
    return IVW;
}

//checks the vector of int that have the indexes of the valid words and searches in the words vector for them and prints them
void PrintValWords(const vector<string> &fileVec, vector<int> indexval) {
    if (!indexval.empty()) {
        cout << " The possible words that can be made are: " << endl;
        for (int x = 0; x < indexval.size(); x++) {
            cout << " " << fileVec[indexval[x]] << endl;
        }
    } else { cout << "There are no possible words made with given letters. " << endl; }
}

// function that asks the user for a set of letters then stores it in a struct organized by letter and compare with the words, then returns the valid words
void GiveWords(const vector<string> &fileVec) {
    vector<struct letterCounter> CTS = ConvertToStruct(fileVec);
    vector<int> indexval;
    string chr;
    cout << "Write all letters in sequence to check for words: ";
    cin >> chr;
    UpperInput(chr);
    letterCounter wordletters = wordsLetters(chr);
    indexval = IndexValWords(CTS, wordletters);
    PrintValWords(fileVec, indexval);

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
// This function searches the file for the bigger word and returns its size.
// Its utility applies when trying to choose the size of a set of letters,
// there is no point giving more letters than those needed to form a word.
int biggerword(const vector<string> &fileVec) {
    int max = fileVec[0].size();
    for (int i = 1; i < fileVec.size(); i++) {
        if (fileVec[i].size() > max) {
            max = fileVec[i].size();
        }
    }
    return max;
}

//This function goes through all words organized in structs and returns a vector of each character average frequency
vector<double> frequencyLetters(const vector<struct letterCounter> &letC) {
    int totalLet = 0;
    vector<float> absolutefreq;
    vector <double> relfreq;
    for (int i = 0; i < letC.size(); i++) {
        totalLet += letC[i].a + letC[i].b + letC[i].c + letC[i].d + letC[i].e + letC[i].f + letC[i].g +         //This cycle calculates the total number of letters, its heavy but its the way to calculate the
                    letC[i].h + letC[i].i + letC[i].j + letC[i].k + letC[i].l + letC[i].m + letC[i].n +         //average
                    letC[i].o + letC[i].p + letC[i].q + letC[i].r + letC[i].s + letC[i].t + letC[i].u +
                    letC[i].v + letC[i].x + letC[i].w + letC[i].y + letC[i].z;
    }
    for (int i2 = 0; i2 < letC.size(); i2++) {
        absolutefreq[0] += letC[i2].a;
        absolutefreq[1] += letC[i2].b;                                          //This cycle stores in a vector the absolute frequency
        absolutefreq[2] += letC[i2].c;                                          // of every letter, that is, how many times they appear on words
        absolutefreq[3] += letC[i2].d;
        absolutefreq[4] += letC[i2].e;
        absolutefreq[5] += letC[i2].f;
        absolutefreq[6] += letC[i2].g;
        absolutefreq[7] += letC[i2].h;
        absolutefreq[8] += letC[i2].i;
        absolutefreq[9] += letC[i2].j;
        absolutefreq[10] += letC[i2].k;
        absolutefreq[11] += letC[i2].l;
        absolutefreq[12] += letC[i2].m;
        absolutefreq[13] += letC[i2].n;
        absolutefreq[14] += letC[i2].o;
        absolutefreq[15] += letC[i2].p;
        absolutefreq[16] += letC[i2].q;
        absolutefreq[17] += letC[i2].r;
        absolutefreq[18] += letC[i2].s;
        absolutefreq[19] += letC[i2].t;
        absolutefreq[20] += letC[i2].u;
        absolutefreq[21] += letC[i2].v;
        absolutefreq[22] += letC[i2].x;
        absolutefreq[23] += letC[i2].w;
        absolutefreq[24] += letC[i2].y;
        absolutefreq[25] += letC[i2].z;
    }
    for (int i3 = 0; i3<absolutefreq.size();i3++) {                   //this cycle transforms the absolute frequency to average, dividing by the total number of letters
        absolutefreq[i3] /= totalLet;
    }
    for (int i4 = 0; i4 < absolutefreq.size(); i4++) {                // this cycle only moves the values to a vector of doubles instead of float to weight less on the execution
        relfreq.push_back(absolutefreq[i4]);
    }
    return relfreq;
}

//This function gets the frequency, constructs a random vector of chars from there and returns it for use
string randsetletters (const vector <struct letterCounter > &letC, const vector<string> &fileVec){
    vector <double> freqlet = frequencyLetters(letC);
    vector <int> absfreq;
    string RSL;
    int sizebigword = biggerword(fileVec)+1;
    srand(time(NULL));
    int sizeofset = rand() % sizebigword+1;     //defines how many letters will be given (here the use of finding the biggest word applies)
    for (int i = 0; i<freqlet.size(); i++) {
        absfreq.push_back(static_cast<int &&>(freqlet[i] * sizeofset));       //This determines how many times each letter will be in the set, given its frequency and size of the set
    }
    for (int i2 = 0; i2 <absfreq.size(); i2++) {
        for(int i3 = absfreq[i2]; i3 > 0 ; i3--) {            // This cycle loads the letters of the set into a string and returns it shuffled
            RSL.push_back(static_cast<char>(i2 + 65));
        }
    }
    next_permutation(RSL.begin(),RSL.end());
    return RSL;
}

//This function is the main structure of this part of the program
//It gives the user the random set of N letters and asks him to
//give a valid input, a word that is validated and belongs to the list
//if he fails, he can always try again indefinitely
void setofLetters(const vector<string> &fileVec) {
    vector<struct letterCounter> letCount = ConvertToStruct(fileVec);
    string setofLet = randsetletters(letCount,fileVec);   //calls the function to return the string of the set with N letters
    cout << "The letters are: " << setofLet << endl;
    string attempt;
    bool valword;
    char anotOp;
    cout << "Write a valid word: ";
    do {
        cin >> attempt;                                                       //after the user attempt, the program searches for it in the list
        valword = binary_search(fileVec.begin(), fileVec.end(), attempt);     // the responds accordingly, allowing infinite retries
        if (valword) {
            cout << "Very Well, that word is valid!" << endl;
            break;
        } else {
            cout << "You guessed wrong.. Do you want to try again? (Y/N) ";
            cin >> anotOp;
        }
    } while (anotOp == 'Y');
}



int main() {
    ifstream file_words;
    vector<string> fileVec;
    OpenToVec(file_words, fileVec);
    vector<letterCounter> lettersVec = ConvertToStruct(fileVec);
    /* testingOTV(fileVec);
    IsWordInList(fileVec); */
//    GiveWords(fileVec);
//    guessWord(fileVec);
 //   wildcardGame(fileVec);
    setofLetters(fileVec);
    return 0;
}