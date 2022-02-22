//
// Created by clay0 on 14.02.2022.
//

#ifndef PASS_RECORD_H
#define PASS_RECORD_H
#include <iostream>
#include <string>
using namespace std;

class Record {
    string service;
    string login;
    string password;

public:

    string getService() { return service; }
    void setService(string &service) { this->service = service; }

    string getLogin() { return login; }
    void setLogin(string &login) { this->login = login; }

    string getPassword() { return password; }
    void setPassword(string &password) { this->password = password; }

    int searchService(string &seacrh, string &keyWord, int &twice);
    string modeMenu(string &newWord, string &keyWord, int &twice);
    string decryptManager(string &encodeWord, string &keyWord, int &twice);
    int newFiles(string &keyWord,int &twice);
    int readFiles(string &keyWord, int &twice);
    int writeFiles(string &keyWord,int &twice);
    int preview();
    int previewCrypto();
    int recordFiles();
};


#endif //PASS_RECORD_H
