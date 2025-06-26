#include "Headers/CaesarCipher.h"
#include <iostream>

CaesarCipher::CaesarCipher() {
    handle = LoadLibrary(TEXT("C:\\Users\\q1112\\source\\repos\\caesarCipher\\caesarCipher.dll"));

    encrypt_ptr = (encrypt_ptr_t)GetProcAddress(handle, "encrypt");
    if (encrypt_ptr == nullptr) {
        std::cout << "Encrypt function not found" << std::endl;
    }

    decrypt_ptr = (decrypt_ptr_t)GetProcAddress(handle, "decrypt");
    if (decrypt_ptr == nullptr) {
        std::cout << "Decrypt function not found" << std::endl;
    }

    if (!encrypt_ptr || !decrypt_ptr) {
        FreeLibrary(handle);
        handle = nullptr;
    }
}

CaesarCipher::~CaesarCipher() {
    if (handle != nullptr) {
        FreeLibrary(handle);
    }
}

bool CaesarCipher::is_loaded() const {
    return handle != nullptr && encrypt_ptr != nullptr && decrypt_ptr != nullptr;
}

std::string CaesarCipher::encrypt(const std::string& text, int key) {
    if (!encrypt_ptr) return "";
    char* result = encrypt_ptr(text.c_str(), key);
    return result;
}

std::string CaesarCipher::decrypt(const std::string& text, int key) {
    if (!decrypt_ptr) return "";
    char* result = decrypt_ptr(text.c_str(), key);
    return result;
}