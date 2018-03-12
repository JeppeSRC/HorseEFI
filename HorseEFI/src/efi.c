#include <efi.h>

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