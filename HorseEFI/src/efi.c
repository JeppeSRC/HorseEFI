#include <efi.h>

#define HORSE_EFI_PRINTF_BUFFER_SIZE 2048
#define ABS(x) (x > 0 ? x : x * -1)

static EFI_HANDLE handle;
static EFI_SYSTEM_TABLE* systable;

CHAR16 chars[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

UINT32 maxCharsU32[17] = { 0, 0, 32, 0, 0, 0, 0, 0, 11, 0, 10, 0, 0, 0, 0, 0, 8 };
UINT32 maxCharsU64[17] = { 0, 0, 64, 0, 0, 0, 0, 0, 22, 0, 20, 0, 0, 0, 0, 0, 16 };

UINT32 uint32ToString(UINT32 v, UINT8 base, CHAR16* buffer) {
	if (v == 0 && base != 16 && base != 2) {
		buffer[0] = '0';
		buffer[1] = 0;
		return 1;
	}

	UINT32 num = 0;

	UINT32 max = maxCharsU32[base];

	while (v > 0) {
		if (num > max) break;
		buffer[num++] = chars[v % base];
		v /= base;
	}

	CHAR16 tmp[32];
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
	if (v == 0 && base != 16 && base != 2) {
		buffer[0] = '0';
		buffer[1] = 0;
		return 1;
	}

	UINT32 num = 0;

	UINT32 max = maxCharsU64[base];

	while (v > 0) {
		if (num > max) break;
		buffer[num++] = chars[v % base];
		v /= base;
	}

	CHAR16 tmp[64];
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
void* memset(void* dst, int v, unsigned long long size) {
	for (UINTN i = 0; i < size; i++) {
		((UINT8*)dst)[i] = v;
	}

	return 0;
}

#pragma function(memcpy)
void* memcpy(void* dst, const void* src, unsigned long long size) {
	for (UINTN i = 0; i < size; i++) {
		((UINT8*)dst)[i] = ((UINT8*)src)[i];
	}

	return 0;
}

#pragma function(strlen)
UINTN strlen(CONST CHAR16* CONST string) {
	UINTN len = 0;

	while (string[len++] != 0);

	return len;
}

#pragma function(strcmp)
int strcmp(CONST CHAR16* CONST str1, CONST CHAR16* CONST str2) {
	int len = 0;

	CHAR16 c = 0;

	while ((c = str1[len++]) != 0) {
		if (c != str2[len-1]) {
			return 0;
		}
	}

	return 1;
}

UINTN startsWith(CONST CHAR16* CONST string, CONST CHAR16* CONST start) {
	UINTN strLen = strlen(string);
	UINTN startLen = strlen(start);

	if (startLen > strLen) {
		return 0;
	}

	for (UINTN i = 0; i < startLen; i++) {
		if (string[i] != start[i]) {
			return 0;
		}
	}

	return 1;
}

VOID print(CONST CHAR16* CONST string) {
	CHAR16* str = (CHAR16*)string;

	UINTN len = strlen(string);

	UINTN last = 0;

	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* out = systable->ConOut;

	UINTN cols = 0;
	UINTN rows = 0;

	out->QueryMode(out, out->Mode->Mode, &cols, &rows);

	for (UINTN i = 0; i < len; i++) {
		if (str[i] == '\n') {
			str[i] = 0;
			systable->ConOut->OutputString(systable->ConOut, str+last);
			
			UINTN spaces = cols - out->Mode->CursorColumn;

			while (spaces--) {
				out->OutputString(out, L" ");
			}

			str[i] = '\n';
			last = i+1;
		}
	}

	if (last != len) {
		systable->ConOut->OutputString(systable->ConOut, str+last);
	}
}

VOID println(CONST CHAR16* CONST string) {
	print(string);
	print(L"\n");
}

VOID clearScreen() {
	systable->ConOut->ClearScreen(systable->ConOut);
}

VOID printf(CONST CHAR16* CONST format, ...) {
	CHAR16 buffer[HORSE_EFI_PRINTF_BUFFER_SIZE];

	va_list args;
	va_start(args, format);
	vsprintf(buffer, HORSE_EFI_PRINTF_BUFFER_SIZE, format, args);
	va_end(args);

	print(buffer);
}

VOID vprintf(CONST CHAR16* CONST format, va_list list) {
	CHAR16 buffer[HORSE_EFI_PRINTF_BUFFER_SIZE];

	vsprintf(buffer, HORSE_EFI_PRINTF_BUFFER_SIZE, format, list);

	print(buffer);
}

UINTN sprintf(CHAR16* CONST buffer, UINTN bufferSize, CONST CHAR16* CONST format, ...) {

	va_list list;
	va_start(list, format);

	return vsprintf(buffer, bufferSize, format, list);
}

UINTN vsprintf(CHAR16* CONST buffer, UINTN bufferSize, CONST CHAR16* CONST format, va_list list) {
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

		if (printed >= bufferSize) return bufferSize;
	}
	
	return (printed << 1);
}

UINTN fprintf(EFI_FILE_PROTOCOL* CONST file, CONST CHAR16* CONST format, ...) {
	CHAR16 buffer[HORSE_EFI_PRINTF_BUFFER_SIZE];

	va_list list;
	
	va_start(list, format);
	UINTN written = vsprintf(buffer, HORSE_EFI_PRINTF_BUFFER_SIZE, format, list) - 2;
	va_end(list);

	EFI_STATUS status = WriteFile(file, &written, buffer);

	if (status != EFI_SUCCESS) {
		written = 0;
		println(L"Failed to write to file\n");
	}

	return written;
}

UINT32 GetGraphicsMode(EFI_GRAPHICS_OUTPUT_PROTOCOL* CONST gop, UINT32* CONST width, UINT32* CONST height, EFI_GRAPHICS_PIXEL_FORMAT* CONST format) {
	EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* pModeInfo = 0;

	EFI_STATUS status = 0;
	UINTN size = 0;

	for (UINT32 i = 0; i < gop->Mode->MaxMode; i++) {
		gop->QueryMode(gop, i, &size, &pModeInfo);
		if (pModeInfo->HorizontalResolution == *width && pModeInfo->VerticalResolution == *height && pModeInfo->PixelFormat == *format) {
			return i;
		}
	}
	
	UINT32 best = ~0;

	if (*width == 0 && *height == 0) {
		best = gop->Mode->MaxMode-1;

		gop->QueryMode(gop, best, &size, &pModeInfo);

		*width = pModeInfo->HorizontalResolution;
		*height = pModeInfo->VerticalResolution;
		*format = pModeInfo->PixelFormat;
	} else {
		UINT32 tmpWidth = *width;
		UINT32 tmpIndex = 0;

		for (UINT32 i = 0; i < gop->Mode->MaxMode; i++) {
			gop->QueryMode(gop, i, &size, &pModeInfo);

			INT32 w = (INT32)pModeInfo->HorizontalResolution;

			INT32 wDiff = w - (INT32)(*width);

			if (ABS(wDiff) < tmpWidth) {
				tmpWidth = ABS(wDiff);
				tmpIndex = i;
			}
		}

		gop->QueryMode(gop, tmpIndex, &size, &pModeInfo);

		*width = pModeInfo->HorizontalResolution;
		*height = pModeInfo->VerticalResolution;
		*format = pModeInfo->PixelFormat;

		best = tmpIndex;
	}
	
	return best;
}

UINTN GetTextMode(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* CONST text, UINTN* CONST columns, UINTN* CONST rows) {
	UINTN c;
	UINTN r;

	if (*columns == 80 && *rows == 25) return 0;

	if (*columns == 80 && *rows == 50) {
		if (text->QueryMode(text, 1, &c, &r) != EFI_UNSUPPORTED) {
			return 1;
		} 

		*rows = 25;

		return 0;
	}

	for (UINTN i = 2; i < text->Mode->MaxMode; i++) {
		text->QueryMode(text, i, &c, &r);

		if (c == *columns && r == *rows) {
			return i;
		}
	}

	UINTN best = text->Mode->MaxMode-1;

	text->QueryMode(text, best, columns, rows);

	return best;
}

EFI_FILE_PROTOCOL* OpenFile(EFI_FILE_PROTOCOL* CONST root, CONST CHAR16* CONST filename, UINT64 openMode, UINT64 attributes) {
	EFI_FILE_PROTOCOL* newFile = 0;

	EFI_STATUS status = root->Open((EFI_FILE_PROTOCOL*)root, &newFile, (CHAR16*)filename, openMode, attributes);

	if (status == EFI_SUCCESS) return newFile;
	
	switch (status) {
		case EFI_NOT_FOUND:
			print(L"File not found: ");
			break;
		case EFI_NO_MEDIA:
			print(L"No media: ");
			break;
		case EFI_MEDIA_CHANGED:
			print(L"Media changed: ");
			break;
		case EFI_DEVICE_ERROR:
			print(L"Device error: ");
			break;
		case EFI_VOLUME_CORRUPTED:
			print(L"Volume corrupted: ");
			break;
		case EFI_WRITE_PROTECTED:
			print(L"Write protected: ");
			break;
		case EFI_ACCESS_DENIED:
			print(L"Access denied: ");
			break;
		case EFI_OUT_OF_RESOURCES:
			print(L"Out of resources: ");
			break;
		case EFI_VOLUME_FULL:
			print(L"Volume full: ");
	}

	printf(L"\"%s\"\n", filename, status);

	return 0;
}

VOID FlushFile(EFI_FILE_PROTOCOL* CONST file) {
	file->Flush(file);
}

VOID CloseFile(EFI_FILE_PROTOCOL* CONST file) {
	file->Close(file);
}

BOOLEAN DeleteFile(EFI_FILE_PROTOCOL* CONST file) {
	return file->Delete(file) == EFI_SUCCESS ? 1 : 0;
}

EFI_STATUS ReadFile(EFI_FILE_PROTOCOL* CONST file, UINTN* CONST size, VOID* CONST buffer) {
	return file->Read(file, size, buffer);
}

EFI_STATUS WriteFile(EFI_FILE_PROTOCOL* CONST file, UINTN* CONST size, CONST VOID* CONST buffer) {
	return file->Write(file, size, (VOID*)buffer);
}

EFI_STATUS SetPosition(EFI_FILE_PROTOCOL* CONST file, UINT64 position) {
	return file->SetPosition(file, position);
}

UINT64 GetPosition(EFI_FILE_PROTOCOL* CONST file) {
	UINT64 pos;

	EFI_STATUS status = file->GetPosition(file, &pos);

	if (status == EFI_UNSUPPORTED) {
		pos = ~0;
	}

	return pos;
}

VOID WaitEscapeAndExit() {
	println(L"Press Escape to exit!");

	EFI_INPUT_KEY key;

	while (1) {
		systable->BootServices->Stall(1000);
		systable->ConIn->ReadKeyStroke(systable->ConIn, &key);

		if (key.ScanCode == 0x17) break;
	}

	systable->RuntimeServices->ResetSystem(EfiResetShutdown, 0, 0, 0);
}