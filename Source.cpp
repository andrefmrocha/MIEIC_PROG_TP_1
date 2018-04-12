#include "Get_Words.h"
#include "Store_Words.h"
int main()
{
    cout << "EXTRACTION OF WORD LIST FROM DICTIONARY" << endl;
    cout << "#######################################" << endl;
    string infile, outfile;
    cout << "Select which file to collect the words from: ";
    cin >> infile;
    cout << "Select which file to store the words at: ";
    cin >> outfile;
    vector<string> word_Vec = get_Dic(infile);
    quickSort(word_Vec);
    cout << "Number of simple words = " << word_Vec.size() << endl;
    remove_Null(word_Vec);
    remove_Duplicates(word_Vec);
    store_Words(word_Vec, outfile);
    cout << "End of processing.";
    return 0;
}