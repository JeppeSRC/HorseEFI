#include <efi.h>

#define HORSE_EFI_PRINTF_BUFFER_SIZE 2048

static EFI_HANDLE handle;
static EFI_SYSTEM_TABLE* systable;

CHAR16 chars[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

UINT32 uint32ToString(UINT32 v, UINT8 base, CHAR16* buffer) {

	UINT32 num = 0;

	while (v > 0) {
		if (num > 10) break;
		buffer[num++] = chars[v % base];
		v /= base;
	}

	CHAR16 tmp[10];
	memcpy(tmp, buffer, sizeof(tmp));

	UINT32 start = 0;

	if (base == 16) {
		for (UINT32 i = 0; i < 9; i++) buffer[i] = '0';
		start = 8 - num;
	}

	for (UINT32 i = 0; i < num; i++) {
		buffer[i + start] = tmp[num - i - 1];
	}

	return num;
}

UINT32 uint64ToString(UINT64 v, UINT8 base, CHAR16* buffer) {

	UINT32 num = 0;

	while (v > 0) {
		if (num > 19) break;
		buffer[num++] = chars[v % base];
		v /= base;
	}

	CHAR16 tmp[19];
	memcpy(tmp, buffer, sizeof(tmp));

	UINT32 start = 0;

	if (base == 16) {
		for (UINT32 i = 0; i < 17; i++) buffer[i] = '0';
		start = 16 - num;
	}

	for (UINT32 i = 0; i < num; i++) {
		buffer[i + start] = tmp[num - i - 1];
	}

	return num;
}

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

VOID print(CONST CHAR16* string) {
	systable->ConOut->OutputString(systable->ConOut, string);
}

VOID printf(CONST CHAR16* format, ...) {
	CHAR16 buffer[HORSE_EFI_PRINTF_BUFFER_SIZE];

	va_list args;
	va_start(args, format);
	vsprintf(buffer, HORSE_EFI_PRINTF_BUFFER_SIZE, format, args);
	va_end(args);

	print(buffer);
}

UINTN sprintf(CHAR16* buffer, UINTN bufferSize, CONST CHAR16* format, ...) {

	va_list list;
	va_start(list, format);

	return vsprintf(buffer, bufferSize, format, list);
}

UINTN vsprintf(CHAR16* buffer, UINTN bufferSize, CONST CHAR16* format, va_list list) {
	if (!buffer || !bufferSize || !format) return ~0;

	UINTN len = strlen(format);
	UINTN printed = 0;

	for (UINTN i = 0; i < len; i++) {
		if (format[i] == '%') {
			i++;
			switch (format[i]) {
				case 'c':
				{
					buffer[printed++] = (CHAR16)va_arg(list, UINTN);
					break;
				}
				case 'C':
				{
					buffer[printed++] = (CHAR16)va_arg(list, UINTN);
					break;
				}
				case 'u':
				{
					CHAR16 tmp[10];

					UINT32 num = uint32ToString((UINT32)va_arg(list, UINTN), 10, tmp);

					memcpy(buffer + printed, tmp, num * sizeof(CHAR16));
					printed += num;
					break;
				}
				case 'U':
				{
					CHAR16 tmp[19];

					UINT32 num = uint64ToString(va_arg(list, UINT64), 10, tmp);

					memcpy(buffer + printed, tmp, num * sizeof(CHAR16));
					printed += num;
					break;
				}
				case 'h':
				{
					CHAR16 tmp[10];

					uint32ToString((UINT32)va_arg(list, UINTN), 16, tmp);

					memcpy(buffer + printed, tmp, 8 * sizeof(CHAR16));
					printed += 8;
					break;
				}
				case 'H':
				{
					CHAR16 tmp[19];

					uint64ToString(va_arg(list, UINT64), 16, tmp);

					memcpy(buffer + printed, tmp, 16 * sizeof(CHAR16));
					printed += 16;
					break;
				}
				case 'S':
				case 's':
				{
					CHAR16* string = va_arg(list, CHAR16*);
					UINTN len = strlen(string)-1;

					memcpy(buffer + printed, string, len * sizeof(CHAR16));
					printed += len;
					break;
				}
			}
		} else {
			buffer[printed++] = format[i];
		}

		if (printed >= bufferSize) return printed;
	}

	buffer[printed++] = 0;
	
	return printed;
}
