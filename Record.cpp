//
// Created by clay0 on 14.02.2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "Record.h"

using namespace std;
string summ;

int Record::newFiles(string &keyWord, int &twice) { //создание нового файла
    ofstream outf("sometext.txt");
    // summ = service +" "+ login +" "+ password;
    outf << modeMenu(service, keyWord, twice) <<" "<< modeMenu(login, keyWord, twice) <<" "<< modeMenu(password, keyWord, twice) << endl;
    // outf << modeMenu(summ, twice) << endl;
    outf.close();
    return 0;
}

int Record::readFiles(string &keyWord, int &twice){
    ifstream openf("sometext.txt"); //чтение файла

    if (!openf) {
        cerr << "Sorry bro our text file cannot be opened" << endl;
        exit(1);
    }
    string strInput;
    while (openf){
        openf >> strInput;
        cout << decryptManager(strInput, keyWord, twice) << " ";
    }
    openf.close();
    return 0;
}

int Record::writeFiles(string &keyWord, int &twice) {
    ofstream wnf("sometext.txt", ios::app); //дозапись
    if (!wnf) {
        cerr << "Sorry bro our text file cannot be opened" << endl;
        exit(1);
    }
    // summ = service +" "+ login +" "+ password;
    if (wnf.is_open()) {
        // wnf << modeMenu(summ, twice) << endl;
        wnf << modeMenu(service, keyWord, twice) <<" "<<modeMenu(login, keyWord, twice) <<" "<< modeMenu(password, keyWord, twice) << endl;
    }
    wnf.close();
    return 0;
}

int Record::preview(){
    cout << "Write name service: "; cin >> service;
    cout << "Enter login from service: "; cin >> login;
    cout << "Enter password from service: "; cin >> password;
    return 0;
}

int Record::previewCrypto(){
    cout << "-----------[modeMenu]-----------" << "\n";
    cout << "Enter <1> : Classic Vigener" << "\n";
    cout << "Enter <2> : Keyword Vigener" << "\n";
    return 0;
}

int Record::recordFiles() {
    int choice, twice, mode;
    string search, keyWord;
    bool cycle = true;
    while (cycle == true){
        cout << "--------------------------------" << "\n";
        cout << "|                              |" << "\n";
        cout << "|          PASSMEMBER          |" << "\n";
        cout << "|                              |" << "\n";
        cout << "--------[Max Nedomolkin]--------" << "\n";
        cout << endl;
        cout << "             *MENU*             " << "\n";
        cout << "        What do you want?       " << "\n";
        cout << "Enter <1> : make a new record" << "\n";
        cout << "Enter <2> : add record" << "\n";
        cout << "Enter <3> : read record" << "\n";
        cout << "Enter <4> : remove records" << "\n";
        cout << "You choice: "; cin >> choice;
        if (choice == 1) {
            preview();
            previewCrypto();
            cout << "Enter type cryptography: "; cin >> twice;
            if (twice == 1)
                newFiles(keyWord, twice);
            else if (twice == 2){
                cout << "Enter key: "; cin >> keyWord;
                newFiles(keyWord, twice);
            }
            cycle = false;
        }else if (choice == 2){
            preview();
            previewCrypto();
            cout << "Enter type cryptography: "; cin >> twice;
            if (twice == 1)
                writeFiles(keyWord, twice);
            else if (twice == 2){
                cout << "Enter key: "; cin >> keyWord;
                writeFiles(keyWord, twice);
            }
            cycle = false;
        }else if (choice == 3){
            cout << "<1> : Read all records" << "\n";
            cout << "<2> : Read record to search" << "\n";
            cout << "Your choice: "; cin >> mode;
            if (mode == 1){
                cout << endl;
                previewCrypto();
                cout << "Enter type description: "; cin >> twice;
                cout << endl;
                if (twice == 1)
                    readFiles(keyWord, twice);
                else if (twice == 2){
                    cout << "Enter type description: "; cin >> twice;
                    readFiles(keyWord, twice);
                }
                cycle = false;
            }else if (mode == 2){
                cout << "Enter search service: "; cin >> search;
                cout << endl;
                previewCrypto();
                cout << "Enter type description: "; cin >> twice;
                if (twice == 1)
                    searchService(search, keyWord, twice);
                else if (twice == 2){
                    cout << "Enter key: "; cin >> keyWord;
                    searchService(search, keyWord, twice);
                }
                cycle = false;
            }
        }else if (choice == 4){
            if (remove("sometext.txt") == 0) {
                cout << "Your records have been deleted successfully" << endl;
                cycle = false;
            }
            else {
                cerr << "Your records couldn't be deleted" << endl;
                cycle = false;
            }
        }else {
            cerr << "Sorry bro, try again" << endl;
            cycle = true;
        }
    }
    return 0;
}