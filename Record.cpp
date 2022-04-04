//
// Created by clay0 on 14.02.2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <windows.h>
#include "Record.h"

using namespace std;

int Record::newFiles(string &keyWord, int &twice) { //создание нового файла
    ofstream outf("sometext.txt");
    outf << modeMenu(service, keyWord, twice) <<" "<< modeMenu(login, keyWord, twice) <<" "<< modeMenu(password, keyWord, twice) << endl;
    outf.close();
    return 0;
}

int Record::readFiles(string &keyWord, int &twice){
    ifstream openf("sometext.txt"); //чтение файла

    if (!openf) {
        cerr << "Sorry bro our text file cannot be opened" << endl;
        exit(1);
    }
    string stroneInput, strtwoInput, strtreeInput;
    while (!openf.eof()) {
        openf >> stroneInput >> strtwoInput >> strtreeInput;
        if (stroneInput !=" " && strtwoInput !=" " && strtreeInput !=" ") {
        cout << decryptManager(stroneInput, keyWord, twice) << " ";
        cout << decryptManager(strtwoInput, keyWord, twice) << " ";
        cout << decryptManager(strtreeInput, keyWord, twice) << endl;
        }
        stroneInput = strtwoInput = strtreeInput = " ";
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
    if (wnf.is_open()) {
        wnf << modeMenu(service, keyWord, twice) <<" "<<modeMenu(login, keyWord, twice) <<" "<< modeMenu(password, keyWord, twice) << endl;
    }
    wnf.close();
    return 0;
}

void Record::preview(){
    cout << "Write name service: "; cin >> service;
    cout << "Enter login from service: "; cin >> login;
    cout << "Enter password from service: "; cin >> password;
}

void Record::previewCrypto(){
    cout << "-----------[modeMenu]-----------" << "\n";
    cout << "Enter <1> : Classic Vigener" << "\n";
    cout << "Enter <2> : Keyword Vigener" << "\n";
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
        cout << "Enter <5> : exit" << "\n";
        cout << "You choice: "; cin >> choice;
        if (choice == 1) {
            preview();
            cout << endl;
            previewCrypto();
            cout << "Enter type cryptography: "; cin >> twice;
            if (twice == 1)
                newFiles(keyWord, twice);
            else if (twice == 2){
                cout << "Enter key: "; cin >> keyWord;
                newFiles(keyWord, twice);
            }
            cout << endl;
            Sleep(3000);
        }else if (choice == 2){
            preview();
            cout << endl;
            previewCrypto();
            cout << "Enter type cryptography: "; cin >> twice;
            if (twice == 1)
                writeFiles(keyWord, twice);
            else if (twice == 2){
                cout << "Enter key: "; cin >> keyWord;
                writeFiles(keyWord, twice);
            }
            cout << endl;
            Sleep(3000);
        }else if (choice == 3){
            cout << "<1> : Read all records" << "\n";
            cout << "<2> : Read record to search" << "\n";
            cout << "Your choice: "; cin >> mode;
            if (mode == 1){
                cout << endl;
                previewCrypto();
                cout << "Enter type description: "; cin >> twice;
                if (twice == 1){
                    cout << endl;
                    readFiles(keyWord, twice);
                }else if (twice == 2){
                    cout << "Enter key: "; cin >> keyWord;
                    cout << endl;
                    readFiles(keyWord, twice);
                }
                cout << endl;
                Sleep(3000);
            }else if (mode == 2){
                cout << "Enter search service: "; cin >> search;
                cout << endl;
                previewCrypto();
                cout << "Enter type description: "; cin >> twice;
                if (twice == 1)
                    searchService(search, keyWord, twice);
                else if (twice == 2){
                    cout << "Enter key: "; cin >> keyWord;
                    cout << endl;
                    searchService(search, keyWord, twice);
                }
            }
            cout << endl;
            Sleep(3000);
        }else if (choice == 4){
            if (remove("sometext.txt") == 0) {
                cout << "Your records have been deleted successfully" << endl;
                cout << endl;
                Sleep(3000);
            }
            else {
                cerr << "Your records couldn't be deleted" << endl;
                cout << endl;
                Sleep(3000);
            }
        }else if (choice == 5)
            cycle = false;
        else {
            cerr << "Sorry bro, try again" << endl;
            cycle = true;
            cout << endl;
            Sleep(3000);
        }
    }
    return 0;
}