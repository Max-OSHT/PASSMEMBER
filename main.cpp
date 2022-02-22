#include <iostream>
#include <fstream>
#include "Record.h"
using namespace std;

int Record::searchService(string &search, string &keyWord, int &twice){
    string newSearch, firstSearch, twoSearch, treeSearch;
    ifstream searchf("sometext.txt");

    if (!searchf) {
        cerr << "Sorry bro our text file cannot be opened" << endl;
        exit(1); 
    }

    while (!searchf.eof()){
        searchf >> firstSearch >> twoSearch >> treeSearch;
        if (firstSearch != " " || twoSearch != " " || treeSearch != " "){
            if (search == decryptManager(firstSearch, keyWord, twice)){
                cout << decryptManager(firstSearch, keyWord, twice) << " ";
                cout << decryptManager(twoSearch, keyWord, twice) << " ";
                cout << decryptManager(treeSearch, keyWord, twice) << " ";
            }
        }
        firstSearch = twoSearch = treeSearch = " ";
    }

    searchf.close();
    return 0;
}


int main() {
    Record test2;
    test2.recordFiles();
    return 0;
}