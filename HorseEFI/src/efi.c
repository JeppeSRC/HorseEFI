#include <efi.h>

static EFI_HANDLE handle;
static EFI_SYSTEM_TABLE* systable;

VOID InitializeLibrary(EFI_HANDLE shit, EFI_SYSTEM_TABLE* systableShit) {
	handle = shit;
	systable = systableShit;
}

#pragma function(memset)
VOID memset(VOID* dst, UINT8 v, UINTN size) {
	for (UINTN i = 0; i < size; i++) {
		((UINT8*)dst)[i] = v;
	}
}

#pragma function(memcpy)
VOID memcpy(VOID* dst, CONST VOID* src, UINTN size) {
	for (UINTN i = 0; i < size; i++) {
		((UINT8*)dst)[i] = ((UINT8*)src)[i];
	}
}

#pragma function(strlen)
UINTN strlen(CONST CHAR16* string) {
	UINTN len = 0;

	while (string[len++] != 0);

	return len;
}
