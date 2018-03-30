#include "Get_Words.h"

int main()
{
    vector<string> word_Vec = get_Dic("29765-8.txt");
    /* Before removing duplicates, it is needed to sort the vector, however that is not needed
       as of now since our test dataset is already ordered */
    quickSort(word_Vec);
    remove_Duplicates(word_Vec);
    remove_Null(word_Vec);
    return 0;
}