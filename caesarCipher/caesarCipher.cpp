#include "caesarCipher.h"
#include "pch.h"
#include <iostream>
#include <cstring>


char* encrypt(const char* rawText, int key) {
    char* encryptedText = new char[strlen(rawText) + 1];
    for (int i = 0; i < strlen(rawText) && rawText[i] != '\0';i++) {
        char ch = rawText[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            encryptedText[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            encryptedText[i] = ch;
        }
        else encryptedText[i] = ch;
    }
    encryptedText[strlen(rawText)] = '\0';
    return encryptedText;
}

char* decrypt(const char* encryptedText, int key) {
    char* decryptedText = new char[strlen(encryptedText) + 1];
    for (int i = 0; i < strlen(encryptedText) && encryptedText[i] != '\0';i++) {
        char ch = encryptedText[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            decryptedText[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            decryptedText[i] = ch;
        }
        else decryptedText[i] = ch;
    }
    decryptedText[strlen(encryptedText)] = '\0';
    return decryptedText;
}