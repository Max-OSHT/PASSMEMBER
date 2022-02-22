//
// Created by clay0 on 08.02.2022.
//
#include <iostream>
#include <string>
#include "Record.h"

using namespace std;


string classicVigener(string &, string &, string &, string &, string &, int &, int &);
string keywordVigener(string &, string &, string &, string &, string &, string &, int &, int &);

string Record::modeMenu(string &newWord, string &keyWord, int &twice) {
    int alf = 26, symb = 37;
    string alfavit = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alfavitMini = "abcdefghijklmnopqrstuvwxyz";
    string symbol = "0123456789!?@#$%^&*_-+=;:(){}[]/|~`,."; //37
    string encodeWord;

    if (twice == 1)
        classicVigener(alfavit, alfavitMini, newWord, encodeWord, symbol, alf, symb);
    else if (twice == 2) {
        keywordVigener(alfavit, alfavitMini, newWord, encodeWord, keyWord, symbol, alf, symb); // ПРИ ИСПОЛЬЗОВАНИИ В ПАРОЛЯХ И ЛОГИНАХ РЕКОМЕНДУЕТСЯ ЗАДАВАТЬ КЛЮЧЕВЫЕ СЛОВА С УЧЕТОМ РАЗЛИЧНЫХ СИВОЛОВ И ЗНАКОВ
    } else {
        cerr << "Sorry bro you are entesr don`t right value" << endl;
        exit(0);
    }
    return encodeWord;
}

int classicReplace(string &, string &, string &, string &, string &, int &, int &, int &, int &, int &);

string classicVigener(string &alfavit, string &alfavitMini, string &newWord, string &encodeWord, string &symbol, int &alf, int &symb) {
    int count = 0, k = 1;
    for (int j = 0; j < newWord.length(); j++) { //проходится по каждой букве введенного слова
        classicReplace(alfavit, alfavitMini, newWord, encodeWord, symbol, alf, count, j, k, symb);
        count++;
        k++;
    }
    cout << "Encode:" << encodeWord << endl;
    return encodeWord;
}

int classicReplace(string &alfavit, string &alfavitMini, string &newWord, string &encodeWord, string &symbol, int &alf, int &count, int &j, int &k, int &symb) {
    for (int i = 0; i < alf; i++) { // проходится по исходному алфавиту
//        cout << alf[(i + count) % 52] << " ";
        if (alfavit[(i + count) % alf] == newWord[j]) { // заменяет исходные буквы при совпадении на буквы со сдвигом
            encodeWord += alfavit[(i + count + k) % alf]; //большой регистр
            break;
        }else if (alfavitMini[(i + count) % alf] == newWord[j]){ // заменяет исходные буквы при совпадении на буквы со сдвигом
            encodeWord += alfavitMini[(i + count + k) % alf]; // маленький регистр
            break;
        }
    }
    for (int q = 0; q < symb; q++){
//        cout << symbol[(q + count) % symb] << " ";
        if (symbol[(q + count) % symb] == newWord[j]){
            encodeWord += symbol[(q + count + k) % symb];
            break;
        }
    }
    return 0;
}

int keywordReplace(string &, string &, string &, string &, string &, string &, int &, int &, int &, int &);
int keywordReplaceMini(string &, string &, string &, string &, string &, string &, int &, int &, int &, int &);
int keywordReplaceSymbol(string &, string &, string &, string &, string &, string &, int &, int &, int &, int &);

string keywordVigener(string &alfavit, string &alfavitMini, string &newWord, string &encodeWord, string &keyWord, string &symbol, int &alf, int &symb) {
    int key = 0;
    for (auto letter : newWord) {
        for (int i = 0; i < alf; i++) { //проходится по каждой букве введенного слова, и если совпадает, то запускается функция
            if (alfavit[i % alf] == letter) {
                keywordReplace(alfavit, newWord, encodeWord, keyWord, alfavitMini, symbol, i, alf, key, symb); //для большого регистра
                break;
            }else if (alfavitMini[i % alf] == letter) {
                keywordReplaceMini(alfavitMini, newWord, encodeWord, keyWord, alfavit, symbol, i, alf, key, symb); // для маленького регистра
                break;
            }
        }
        for (int i = 0; i < symb; i++) {
            if (symbol[i % symb] == letter) {
                keywordReplaceSymbol(symbol, newWord, encodeWord, keyWord, alfavit, alfavitMini, i, key, symb, alf); // для символов и цифр
                break;
            }
        }
    }
    // cout << "Encode:" << encodeWord << endl;
    return encodeWord;
}

int keywordReplace(string &alfavit, string &newWord, string &encodeWord, string &keyWord, string &alfavitMini, string &symbol, int &i, int &alf, int &key, int &symb) {
    int count = 0;
    for (int j = 0; j < alf; j++) { //проходится по каждой букве алфавита в поисках буквы ключа и перед поиском каждой буквы работает счетчик, который участвует в поске каждой закодированной буквы
        if (alfavit[j % alf] == keyWord[key]) 
            break;
        else if (symbol[j % symb] == keyWord[key])
            break;
        else if (alfavitMini[j % alf] == keyWord[key])
            break;
        count++;
    }
    key++;
    if (keyWord.length() == key)
        key = 0;
    encodeWord += alfavit[(i + count) % alf];
    return 0;
}

int keywordReplaceMini(string &alfavitMini, string &newWord, string &encodeWord, string &keyWord, string &alfavit, string &symbol, int &i, int &alf, int &key, int &symb){
    int count = 0;
    for (int j = 0; j < alf; j++) { //проходится по каждой букве алфавита в поисках буквы ключа и перед поиском каждой буквы работает счетчик, который участвует в поске каждой закодированной буквы
        if (alfavitMini[j % alf] == keyWord[key])
            break;
        else if (symbol[j % symb] == keyWord[key])
            break;
        else if (alfavit[j % alf] == keyWord[key])
            break;
        count++;
    }
    key++;
    if (keyWord.length() == key)
        key = 0;
    encodeWord += alfavitMini[(i + count) % alf];
    return 0;
}

int keywordReplaceSymbol(string &symbol, string &newWord, string &encodeWord, string &keyWord, string &alfavit, string &alfavitMini, int &i, int &key, int &symb, int &alf){
    int count = 0;
    for (int j = 0; j < symb; j++) { //проходится по каждому символу в поисках символа ключа и перед поиском каждого символа работает счетчик, который участвует в поске каждого закодированного символа
        if (symbol[j % symb] == keyWord[key])
            break;
        else if (alfavit[j % alf] == keyWord[key])
            break;
        else if (alfavitMini[j % alf] == keyWord[key])
            break;
        count++;
    }
    key++;
    if (keyWord.length() == key)
        key = 0;
    encodeWord += symbol[(i + count) % symb];
    return 0;
}