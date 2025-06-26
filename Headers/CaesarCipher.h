#pragma once
#include <windows.h>
#include <string>

typedef char* (*encrypt_ptr_t)(const char* rawText, int key);
typedef char* (*decrypt_ptr_t)(const char* encryptedText, int key);

class CaesarCipher {
    HINSTANCE handle = nullptr;
    encrypt_ptr_t encrypt_ptr;
    decrypt_ptr_t decrypt_ptr;

public:
    CaesarCipher();

    ~CaesarCipher();

    bool is_loaded() const;

    std::string encrypt(const std::string& raw_text, int key);
    std::string decrypt(const std::string& encrypted_text, int key);
};
