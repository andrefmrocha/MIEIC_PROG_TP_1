//
// Created by joaom on 23-03-2018.
//

#include "Program_2.h"

using namespace std;

// Open file e go through each line extrating it to the vector with push_back
void OpenToVec(ifstream &file_words, vector<string> &fileVec, string filename) {
    file_words.open(filename);
    while (!file_words.is_open()) //verifies correct file opening
    {
        cout << "File not found! Please write the name of the file again:"<< endl;
		cin >> filename;
        file_words.open(filename);
    }
    string line;
    while (getline(file_words, line)) {  //this cycle gets all the words from the file and pushes them into a vector
        fileVec.push_back(line);         //in order to be easily manipulated by the program functions
    }
    file_words.close();
}

//String manipulation function that makes the program case insensitive by receiving the user input,
// whether its capitalized or not and alters it so be readble by the program functions

void UpperInput(string &input) {
    for (int i = 0; i < input.length(); i++) {
        input[i] = toupper(input[i]);  //goes through the string using toupper to every character belonging to the string
    }
}

// Asks the user for the input string, searches it and check if its valid or not.
void IsWordInList(const vector<string> &fileVec) {
    string target;
    cout << "What is the word you want to search?" << endl;
    cin >> target;
    UpperInput(target);   
    while(invalidWord(target))
    {
        cout << "Invalid Word, please type again :" << endl;
        cin >> target;
        UpperInput(target);
    }
    bool valOp;
    valOp = binary_search(fileVec.begin(), fileVec.end(), target);   // Using the binary search algorithm from std library
    if (valOp) {                                                      // to ease the program building
        cout << "The word is valid." << endl;
    } else {
        cout << "The word was not found. " << endl;
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
            if (valWords[i].find_first_of(setLetters[i2]) == string::npos) {     //this condition checks if every letter of the user given set belongs to a certain word
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
vector<letterCounter> ConvertToStruct(const vector<string> &fileVec) {
    vector<letterCounter> CTS;
    for (int i = 0; i < fileVec.size(); i++) {
        letterCounter letword = wordsLetters(fileVec[i]);
        CTS.push_back(letword);
    }
    return CTS;
}

// function that compares the structs of words, to check if they have the same letters and returns the indexes of the valid words to a vector
vector<int> IndexValWords(vector<letterCounter> lettersVec,letterCounter wordletters) {
    vector<int> IVW;
    letterCounter *ptr1, *ptr2;
    ptr1 = &wordletters;
    for (int i = 0; i < lettersVec.size(); i++) {
        ptr2 = &lettersVec[i];
        if (memcmp(ptr1, ptr2, sizeof(wordletters)) == 0) {
            IVW.push_back(i);
        }
    }
    return IVW;
}

//checks the vector of int that have the indexes of the valid words and searches in the words vector for them and prints them
void PrintValWords(const vector<string> &fileVec,const vector<int> &indexval) {
    if (!indexval.empty()) {
        cout << " The possible words that can be made are: " << endl;
        for (int x = 0; x < indexval.size(); x++) {
            cout << x+1 << " - " << fileVec[indexval[x]] << endl;
        }
    } else { cout << "There are no possible words made with given letters. " << endl; }
}

// function that asks the user for a set of letters then stores it in a struct organized by letter and compare with the words, then returns the valid words
void GiveWords(const vector<string> &fileVec,const vector<letterCounter> &lettersVec ) {
    vector<int> indexval;
    string chr;
    cout << "Write all letters in sequence to check for words: ";
    cin >> chr;
    UpperInput(chr);
    while(invalidWord(chr))
    {
        cout << "Invalid Word, please type again :" << endl;
        cin >> chr;
        UpperInput(chr);
    }
    letterCounter wordletters = wordsLetters(chr);
    indexval = IndexValWords(lettersVec, wordletters);
    PrintValWords(fileVec, indexval);
}

//This function selects a word randomly from the list, scrambles it and return a vector of the word to be guessed and the scrambled one
vector<string> randomWord(const vector<string> &fileVec) {
    srand((time(NULL)));
    int wordI = rand() % fileVec.size();   // randomly selects an index from the file vector
    string word = fileVec[wordI];          // stores the selected word
    string rword = fileVec[wordI];         // creates a copy of the word
    next_permutation(rword.begin(), rword.end());     // scrambles the chars in the vector
    vector<string> words;                              //returns the right word and the scrambled word
    words.push_back(word);
    words.push_back(rword);
    return words;
}

//this function returns true if the user input is found in the list of words composed by a certain set of letters
bool WordIsValid(const string &guess, const vector <int> &IVW, const vector <string> &fileVec)
{
	for (int i = 0; i < IVW.size(); i++) {
		if (guess == fileVec[IVW[i]])
			return true;
	}
	return false;
}
//This function interacts with user, giving in a scrambled word to guess with 3 tries, if not successful, a 'end of game' message shall appear
void guessWord(const vector<string> &fileVec,const vector <letterCounter> &lettersVec) {
	vector<string> words = randomWord(fileVec);
    string rword = words[1];                          // gets a random word and its scrambled copy from the randomWord function
    string word = words[0];             
	struct letterCounter RSL = wordsLetters(rword);
	letterCounter GSL;
	vector <int> IVW = IndexValWords(lettersVec, RSL);
	bool valword; 
	string guess;
    bool flag = false;           //this flag will set if the user won the game or not
    cout << "The word to guess is " << rword << ". What is your guess? ";
    for (int i = 3; i >
                    0; i--) {                   
        cin >> guess;
        UpperInput(guess);
        while(invalidWord(guess))
        {
            cout << "Invalid Word, please type again: " << endl;
            cin >> guess;
            UpperInput(guess);
        }
		valword = WordIsValid(guess, IVW, fileVec);
        if (valword) {                                                //the user has 3 tries to guess the word
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
    int max = fileVec[0].length();
    for (int i = 1; i < fileVec.size(); i++) {
        if (fileVec[i].length() > max) {
            max = fileVec[i].length();
        }
    }
    return max;
}

//This function adds calculates the number of appearences of every letter in the list and multiplies it by a weight to give
//a proportional frequency of the letters
vector<double> frequencyLetters(const vector<letterCounter> &letC) {
    vector<int> absolutefreq;
    absolutefreq.resize(26);
    vector<double> relfreq;
    for (int i2 = 0; i2 < letC.size(); i2++) {
        absolutefreq[0] += letC[i2].a;
        absolutefreq[1] += letC[i2].b;                            //This cycle stores in a vector the absolute frequency
        absolutefreq[2] += letC[i2].c;                            // of every letter, that is, how many times they appear on words
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
    for (int i3 = 0; i3 < absolutefreq.size(); i3++) {         //this cycle multiplies the absolute frequency with a default weight (0.3)
        relfreq.push_back(static_cast<double> (absolutefreq[i3]) *0.3); //so it can be proportional and the size of the vector much smaller
    }
    return relfreq;
}

//This function gets the frequency of letters, stores the letters in a vector accordingly to its frequency
string randsetletters(const vector<letterCounter> &lettersVec, const vector<string> &fileVec) {    //and builds a random string from there (the smaller set)
    vector<double> freqlet = frequencyLetters(lettersVec);
    vector<char> absfreq;
    string RSL;  //this is where the desired set of letters will be stored
    int sizebigword = biggerword(fileVec) + 1;
    srand(time(NULL));
    int sizeofset = rand() % sizebigword;     //defines how many letters will be given (here the use of finding the biggest word applies)
    int ntimes;
    for (int i = 0; i < freqlet.size(); i++) {          //this cycle stores in a vector each letter n times, n being its frequency
        ntimes = lround(freqlet[i]);
        if (ntimes < 2) ntimes = 2;
        for (int i2 = ntimes; i2 > 0; i2--)
            absfreq.push_back(static_cast<char> (i + 65));
    }
    for (int i3 = 0; i3 < sizeofset; i3++) {           //this cycle stores in the final set a random set of letters chose from the bigger set
        RSL.push_back(absfreq[rand() % absfreq.size()]);
    }
    next_permutation(RSL.begin(), RSL.end());   //this function shuffles the string to appear more randomized
    return RSL;
}

//this function verifies if the user built a word using the given set of letters
bool rightsetletters(const string &setofLet, const string &attempt) {
    for (int i = 0; i < setofLet.length(); i++) {
        if (attempt.find_first_of(setofLet[i])==string::npos) {  //if the function doesnt find in the attempt the letters from
            return false;                                        //the given set, it returns false
        }
    }
    return true;
}

//This function is the main structure of this part of the program
//It gives the user the random set of N letters and asks him to
//give a valid input, a word that is validated to if belongs to the list
//if he fails, he can always try again indefinitely
void setofLetters(const vector<string> &fileVec, const vector<letterCounter> &lettersVec) {
    string setofLet ;
    struct letterCounter SOL;
    vector <int> IVW;
    do {
        setofLet = randsetletters(lettersVec,fileVec);//calls the function to return the string of the set with N letters
        SOL = wordsLetters(setofLet);
        IVW = IndexValWords(lettersVec,SOL); // this function verifies in the string created actually can be build a word
    } while (IVW.empty());    // and will repeat the process until a valid string is formed
    cout << "The letters are: " << setofLet << endl;
    string attempt;
    bool valword;
    bool rightguess= false;
    string anotOp = "N";
    anotOp.resize(1);
    cout << "Write a valid word: " << endl;
    do {
        cin >> attempt;                   //after the user attempt, the program searches for it in the list
        UpperInput(attempt);
        while(invalidWord(attempt))
        {
            cout << "Invalid Word, please type again :" << endl;
            cin >> attempt;
            UpperInput(attempt);
        }
        valword = binary_search(fileVec.begin(), fileVec.end(), attempt);     // and responds accordingly, allowing infinite retries
        rightguess = rightsetletters(setofLet, attempt);  //checks if the user used the same letters from the given set
        if (valword && rightguess) {                // if both conditions verify, the user wins the game
            cout << "Very Well, that word is valid!" << endl;
            break;
        } else if (valword && !rightguess) { //if he builds a valid word but with other words, he loses, no cheating allowed.
            cout << "You built a valid word, but using the different letters from the given. No cheating!" << endl;
        } else {                         //if he fails, he can always try again until he gets it right
            cout << "There are no words using those letters.. Do you want to try again? (Y/N) "<< endl;
            cin >> anotOp;
            while( anotOp != "Y" && anotOp != "N")
            {
                cout << "Invalid response, please type again :" << endl;
                cin >> anotOp;
                UpperInput(anotOp);
            }
        }
    } while (anotOp == "Y");
}