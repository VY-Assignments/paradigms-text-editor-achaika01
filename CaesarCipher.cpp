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

std::vector<std::byte> CaesarCipher::encrypt(const std::vector<std::byte>& data, int key){
    if (!encrypt_ptr) return {};
    
    std::vector<std::byte> result(data.size());
    encrypt_ptr(reinterpret_cast<const unsigned char*>(data.data()),
        reinterpret_cast<unsigned char*>(result.data()),
        data.size(), key);

    return result;       
}

std::vector<std::byte> CaesarCipher::decrypt(const std::vector<std::byte>& data, int key) {
    if (!decrypt_ptr) return {};
    
    std::vector<std::byte> result(data.size());
    decrypt_ptr(reinterpret_cast<const unsigned char*>(data.data()),
        reinterpret_cast<unsigned char*>(result.data()),
        data.size(), key);

    return result;
}