#include "Get_Words.h"
#include "Store_Words.h"
int main()
{
    string filename;
    cout << "Select which file to use: ";
    cin >> filename;
    vector<string> word_Vec = get_Dic(filename);
    /* Before removing duplicates, it is needed to sort the vector, however that is not needed
       as of now since our test dataset is already ordered */
    quickSort(word_Vec);
    remove_Duplicates(word_Vec);
    remove_Null(word_Vec);
    store_Words(word_Vec);
    return 0;
}