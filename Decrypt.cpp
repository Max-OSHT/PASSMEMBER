#include <iostream>
#include <string>
#include "Record.h"

using namespace std;
string decryptVigenerKey(string &, string &, string &, string &, string &, string &, int &, int &);
string decryptVigenerClassic(string &, string &, string &, string &, string &, int &, int &);

string Record::decryptManager(string &encodeWord, string &keyWord, int &twice){
    int alf = 26, symb = 37;
    string alfavit = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alfavitMini = "abcdefghijklmnopqrstuvwxyz";
    string symbol = "0123456789!?@#$%^&*_-+=;:(){}[]/|~`,."; //37
    string WantWord;

    if (twice == 1)
        decryptVigenerClassic(alfavit, alfavitMini, encodeWord, symbol, WantWord, alf, symb);
    else if (twice == 2){
        decryptVigenerKey(alfavit, alfavitMini, encodeWord, keyWord, symbol, WantWord, alf, symb);
    }else {
        cerr << "Sorry bro you are enter don`t right value" << endl;
        exit(0);
    }
    return WantWord;
}

int decryptClassic(string &, string &, string &, string &, string &, int &, int &, int &, int &, int &);

string decryptVigenerClassic(string &alfavit, string &alfavitMini, string &encodeWord, string &symbol, string &WantWord, int &alf, int &symb){
    int count = 0, k = -1;
    for (int j = 0; j < encodeWord.length(); j++){
        decryptClassic(alfavit, alfavitMini, encodeWord, symbol, WantWord, alf, symb, count, k, j);
        count++;
        k++;
    }
    return WantWord;
}

int decryptClassic(string &alfavit, string &alfavitMini, string &encodeWord, string &symbol, string &WantWord, int &alf, int &symb, int &count, int &k, int &j){
    bool flag = true;
    for (int i = 0; i < alf; i++) { // проходится по исходному алфавиту
        if (alfavit[(i + count) % alf] == encodeWord[j]) { // заменяет исходные буквы при совпадении на буквы со сдвигом
            WantWord += alfavit[(i - count + k + alf) % alf]; //большой регистр
            flag = false;
            break;
        }else if (alfavitMini[(i + count) % alf] == encodeWord[j]){ // заменяет исходные буквы при совпадении на буквы со сдвигом
            WantWord += alfavitMini[(i - count + k + alf) % alf]; // маленький регистр
            flag = false;
            break;
        }
    }
    if (flag == true){
        for (int q = 0; q < symb; q++){
            if (symbol[(q + count) % symb] == encodeWord[j]){
                WantWord += symbol[(q - count + k + symb) % symb];
                break;
            }
        }
    }   
    return 0;
}

int decryptVigenerAfavit(string &, string &, string &, string &, string &, string &, int &, int &, int &, int &);
int decryptVigenerAfavitMini(string &, string &, string &, string &, string &, string &, int &, int &, int &, int &);
int decryptVigenerSymbol(string &, string &, string &, string &, string &, string &, int &, int &, int &, int &);

string decryptVigenerKey(string &alfavit, string &alfavitMini, string &encodeWord, string &keyWord, string &symbol, string &WantWord, int &alf, int &symb){
    int q = 0;
    for (auto letter : encodeWord){
        for (int j = 0; j < alf; j++){
            if (alfavit[j % alf] == letter){
                decryptVigenerAfavit(alfavit, alfavitMini, encodeWord, keyWord, symbol, WantWord, alf, symb, j, q); // большой регистр
                break;
            }else if (alfavitMini[j % alf] == letter){
                decryptVigenerAfavitMini(alfavit, alfavitMini, encodeWord, keyWord, symbol, WantWord, alf, symb, j, q); //маленький регистр 
                break;
            }
        }
       
        for (int j = 0; j < symb; j++){
            if (symbol[j % symb] == letter){
                decryptVigenerSymbol(alfavit, alfavitMini, encodeWord, keyWord, symbol, WantWord, alf, symb, j, q); //символы
                break;
            }
        }
    }
    return WantWord;
}



int decryptVigenerAfavit(string &alfavit, string &alfavitMini, string &encodeWord, string &keyWord, string &symbol, string &WantWord, int &alf, int &symb, int &j, int &q){
    int count = 0;
    bool check = true;
    for (int i = 0; i < alf; i++){
        if (alfavit[i % alf] == keyWord[q]){
            check = false;
            break;
        }else if (alfavitMini[i % alf] == keyWord[q]){
            check = false;
            break;
        }
        count++;
    }
    if (check == true) // обнуление счетчика, если в верхнем цикле не выполнилось ни одного условия
        count = 0;
    if (check == true){
        for (int i = 0; i < symb; i++){
            if (symbol[i % symb] == keyWord[q])
                break;
            count++;
        }
    }
    q++;
    if (keyWord.length() == q)
        q = 0;
    if (count <= j)
        WantWord += alfavit[(j - count) % alf];
    else
        WantWord += alfavit[(j - count + alf) % alf]; // чтобы индекс не уходил в минусовую область
    return 0;
}

int decryptVigenerAfavitMini(string &alfavit, string &alfavitMini, string &encodeWord, string &keyWord, string &symbol, string &WantWord, int &alf, int &symb, int &j, int &q){
    int count = 0;
    bool check = true;
    for (int i = 0; i < alf; i++){
        if (alfavitMini[i % alf] == keyWord[q]){
            check = false;
            break;
        }else if (alfavit[i % alf] == keyWord[q]){
            check = false;
            break;
        }
        count++;
    }
    if (check == true) // обнуление счетчика, если в верхнем цикле не выполнилось ни одного условия
        count = 0;
    if (check == true){
        for (int i = 0; i < symb; i++){
            if (symbol[i % symb] == keyWord[q])
                break;
            count++;
        }
    }
    q++;
    if (keyWord.length() == q)
        q = 0;
    if (count <= j)
        WantWord += alfavitMini[(j - count) % alf];
    else
        WantWord += alfavitMini[(j - count + alf) % alf]; // чтобы индекс не уходил в минусовую область
    return 0;
}

int decryptVigenerSymbol(string &alfavit, string &alfavitMini, string &encodeWord, string &keyWord, string &symbol, string &WantWord, int &alf, int &symb, int &j, int &q){
    int count = 0;
    bool check = true;
    for (int i = 0; i < alf; i++){
        if (alfavit[i % alf] == keyWord[q]){
            check = false;
            break;
        }else if (alfavitMini[i % alf] == keyWord[q]){
            check = false;
            break;
        }
        count++;
    }
    if (check == true) // обнуление счетчика, если в верхнем цикле не выполнилось ни одного условия
        count = 0;
    if (check == true){
        for (int i = 0; i < symb; i++){
            if (symbol[i % symb] == keyWord[q])
                break;
            count++;
        }
    }
    q++;
    if (keyWord.length() == q)
        q = 0;
    if (count <= j)
        WantWord += symbol[(j - count) % symb];
    else
        WantWord += symbol[(j - count + symb) % symb]; // чтобы индекс не уходил в минусовую область
    return 0;
}