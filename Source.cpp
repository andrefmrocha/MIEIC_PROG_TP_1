#include "Get_Words.h"

int main()
{
    vector<string> word_Vec = get_Dic("Teste.txt");
    /* Before removing duplicates, it is needed to sort the vector, however that is not needed
       for now since our dataset is already ordered */
    remove_Duplicates(word_Vec);
    return 0;
}