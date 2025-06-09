#pragma once

extern "C" {

	__declspec(dllexport) char* encrypt(const char* rawText, int key);
	__declspec(dllexport) char* decrypt(const char* encryptedText, int key);

}
