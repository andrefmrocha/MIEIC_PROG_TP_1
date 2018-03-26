#include "Get_Words.h"
int main()
{
    ifstream infile = get_dic("Testes.txt");
    vector<string> word_Vec = get_Words(infile);

    return 0;
}