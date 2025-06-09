#include <iostream>
#include <windows.h>
using namespace std;

typedef char* (*encrypt_ptr_t)(const char* rawText, int key);
typedef char* (*decrypt_ptr_t)(const char* encryptedText, int key);

int main() {
	HINSTANCE handle = LoadLibrary(TEXT("C:\\Users\\q1112\\source\\repos\\caesarCipher\\caesarCipher.dll"));
	if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
	{
		cout << "Lib not found" << endl;
		return 1;
	}


	encrypt_ptr_t encrypt_ptr = (encrypt_ptr_t)GetProcAddress(handle, "encrypt");
	if (encrypt_ptr == nullptr)
	{
		cout << "Function not found" << endl;
		return 1;
	}

	decrypt_ptr_t decrypt_ptr = (decrypt_ptr_t)GetProcAddress(handle, "decrypt");
	if (decrypt_ptr == nullptr)
	{
		cout << "Function not found" << endl;
		return 1;
	}

	const char* message = "TuTorIaL";
	char* encrypted = encrypt_ptr(message, 3);
	char* decrypted = decrypt_ptr(encrypted, 3);

	std::cout << "Encrypted: " << encrypted << "\n";
	std::cout << "Decrypted: " << decrypted << "\n";


	FreeLibrary(handle);
}