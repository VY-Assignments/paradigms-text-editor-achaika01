#pragma once
#include <windows.h>
#include <string>
#include <cstddef>
#include <vector>

typedef char* (*encrypt_ptr_t)(const unsigned char*, unsigned char*, size_t, int);
typedef char* (*decrypt_ptr_t)(const unsigned char*, unsigned char*, size_t, int);

class CaesarCipher {
    HINSTANCE handle = nullptr;
    encrypt_ptr_t encrypt_ptr;
    decrypt_ptr_t decrypt_ptr;

public:
    CaesarCipher();

    ~CaesarCipher();

    std::vector<std::byte> encrypt(const std::vector<std::byte>& data, int key);
    std::vector<std::byte> decrypt(const std::vector<std::byte>& data, int key);
};
