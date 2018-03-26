//
// Created by joaom on 23-03-2018.
//
#include "Program_2.h"
using namespace std;

// Abre ficheiro e percorre cada linha extraindo para o vetor atraves do push_back
void OpenToVec(ifstream &file_words, vector <string> &fileVec)
{
    file_words.open("Ex_P2.txt");
    if (file_words.fail()) {
        cerr << "Input file opening failed.\n";   // mensagem de erro ao abrir ficheiro
        exit(1);
    }
    string line;
    while (getline(file_words, line)) {
        fileVec.push_back(line);
    }
    file_words.close();
}

//funcao de teste para verificar que o vetor tem todas as palavras do ficheiro
void testingOTV (vector <string> fileVec)
{
    for (int i = 0; i < fileVec.size(); i++)
    {
        cout << fileVec[i]<<endl;
    }
}

int main()
{
    ifstream file_words;
    vector <string> fileVec;
    OpenToVec(file_words,fileVec);
    testingOTV(fileVec);
    return 0;

}