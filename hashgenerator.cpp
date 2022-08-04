
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <wincrypt.h>
#include <string>
#include <inttypes.h>
#pragma comment (lib, "crypt32.lib")

DWORD64 djb2(PBYTE str) {
	DWORD64 dwHash = 0x7734773477347734;
	INT c;

	while (c = *str++)
		dwHash = ((dwHash << 0x5) + dwHash) + c;

	return dwHash;
}

int main()
{
	PBYTE str = (PBYTE)("NtMapViewOfSection"); //Change "NtMapViewOfSection" to any ntdll function you need.
	DWORD64 dwHash = djb2(str);
	printf("%I64x\n", dwHash);
}

