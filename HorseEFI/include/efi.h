#pragma once


/*
_______________________________________________
|     UEFI memory types        | Legacy types |
| EfiReservedMemoryType        |              |
| EfiRuntimeServicesCode       |              |
| EfiRuntimeServicesData       |  Reserved    |
| EfiMemoryMappedIO            |              |
| EfiMemoryMappedIOPortSpace   |              |
| EfiPalCode                   |              |
| EfiUnusableMemory            |  bad memory  |
| EfiACPIReclaimMemory         | ACPI reclaim |
| EfiLoaderCode                |              |
| EfiLoaderData                |              |
| EfiBootServicesCode          |   Usable     |
| EfiBootServicesData          |              |
| EfiConventionalMemory        |              |
| EfiACPIMemoryNVS             | ACPI NVS     |
*/
//definitions
#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))
#define EFI_SYSTEM_TABLE_REVISION EFI_2_70_SYSTEM_TABLE_REVISION
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

#define EFI_SUCCESS 0

#ifdef _M_AMD64
#define HIGH_BIT (1ULL << 63)
#else 
#define HIGH_BIT (1 << 31)
#endif

#define EFI_LOAD_ERROR				(1  | HIGH_BIT)
#define EFI_INVALID_PARAMETER		(2  | HIGH_BIT)
#define EFI_UNSUPPORTED				(3  | HIGH_BIT)
#define EFI_BAD_BUFFER_SIZE			(4  | HIGH_BIT)
#define EFI_BUFFER_TOO_SMALL		(5  | HIGH_BIT)
#define EFI_NOT_READY				(6  | HIGH_BIT)
#define EFI_DEVICE_ERROR			(7  | HIGH_BIT)
#define EFI_WRITE_PROTECTED			(8  | HIGH_BIT)
#define EFI_OUT_OF_RESOURCES		(9  | HIGH_BIT)
#define EFI_VOLUME_CORRUPTED		(10 | HIGH_BIT)
#define EFI_VOLUME_FULL				(11 | HIGH_BIT)
#define EFI_NO_MEDIA				(12 | HIGH_BIT)
#define EFI_MEDIA_CHANGED			(13 | HIGH_BIT)
#define EFI_NOT_FOUND				(14 | HIGH_BIT)
#define EFI_ACCESS_DENIED			(15 | HIGH_BIT)
#define EFI_NO_RESPONSE				(16 | HIGH_BIT)
#define EFI_NO_MAPPING				(17 | HIGH_BIT)
#define EFI_TIMEOUT					(18 | HIGH_BIT)
#define EFI_NOT_STARTED				(19 | HIGH_BIT)
#define EFI_ALREADY_STARTED			(20 | HIGH_BIT)
#define EFI_ABORTED					(21 | HIGH_BIT)
#define EFI_ICMP_ERROR				(22 | HIGH_BIT)
#define EFI_TFTP_ERROR				(23 | HIGH_BIT)
#define EFI_PROTOCOL_ERROR			(24 | HIGH_BIT)
#define EFI_INCOMPATIBLE_VERSION	(25 | HIGH_BIT)
#define EFI_SECURITY_VIOLATION		(26 | HIGH_BIT)
#define EFI_CRC_ERROR				(27 | HIGH_BIT)
#define EFI_END_OF_MEDIA			(28 | HIGH_BIT)
#define EFI_END_OF_FILE				(31 | HIGH_BIT)
#define EFI_INVALID_LANGUAGE		(32 | HIGH_BIT)
#define EFI_COMPROMISED_DATA		(33 | HIGH_BIT)
#define EFI_IP_ADDRESS_CONFLICT		(34 | HIGH_BIT)
#define EFI_HTTP_ERROR				(35 | HIGH_BIT)

#define EFI_WARN_UNKNOW_GLYPH		1
#define EFI_WARN_DELETE_FAILURE		2
#define	EFI_WARN_WRITE_FAILURE		3
#define EFI_WARN_BUFFER_TOO_SMALL	4
#define EFI_WARN_STALE_DATA			5
#define EFI_WARN_FILE_SYSTEM		6


#define EFIAPI __cdecl

#define IN 
#define OUT 
#define OPTIONAL 
#define CONST const


typedef unsigned char									BOOLEAN;
typedef signed char										INT8;
typedef unsigned char									UINT8;
typedef signed short									INT16;
typedef unsigned short									UINT16;
typedef signed int										INT32;
typedef unsigned int									UINT32;
typedef signed long long								INT64;
typedef unsigned long long								UINT64;

#ifdef _M_AMD64
typedef INT64											INTN;
typedef UINT64											UINTN;
#else
typedef INT32											INTN;
typedef UINT32											UINTN;
#endif

typedef char											CHAR8;
typedef short											CHAR16;

typedef void											VOID;
typedef UINTN											EFI_STATUS;

typedef VOID* EFI_EVENT;

typedef UINTN EFI_TPL;

#define TPL_APPLICATION 4
#define TPL_CALLBACK 8
#define TPL_NOTIFY 16
#define TPL_HIGH_LEVEL 31

#define EVT_TIMER 0x80000000
#define EVT_RUNTIME 0x40000000
#define EVT_NOTIFY_WAIT 0x00000100
#define EVT_NOTIFY_SIGNAL 0x00000200
#define EVT_SIGNAL_EXIT_BOOT_SERVICES 0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE 0x60000202

#define EFI_EVENT_GROUP_EXIT_BOOT_SERVICES \
 {0x27abf055, 0xb1b8, 0x4c26, 0x80, 0x48, 0x74, 0x8f, 0x37,\
 0xba, 0xa2, 0xdf}}
#define EFI_EVENT_GROUP_VIRTUAL_ADDRESS_CHANGE \
 {0x13fa7698, 0xc831, 0x49c7, 0x87, 0xea, 0x8f, 0x43, 0xfc,\
 0xc2, 0x51, 0x96}
#define EFI_EVENT_GROUP_MEMORY_MAP_CHANGE \
 {0x78bee926, 0x692f, 0x48fd, 0x9e, 0xdb, 0x1, 0x42, 0x2e, \
 0xf0, 0xd7, 0xab}
#define EFI_EVENT_GROUP_READY_TO_BOOT \
 {0x7ce88fb3, 0x4bd7, 0x4679, 0x87, 0xa8, 0xa8, 0xd8, 0xde,\
 0xe5,0xd, 0x2b}
#define EFI_EVENT_GROUP_RESET_SYSTEM \
{ 0x62da6a56, 0x13fb, 0x485a, 0xa8, 0xda, 0xa3, 0xdd, 0x79, 0x12, 0xcb, 0x6b }

typedef VOID(EFIAPI *EFI_EVENT_NOTIFY) (IN EFI_EVENT Event, IN VOID *Context);

typedef
EFI_STATUS
(EFIAPI *EFI_CREATE_EVENT) (
	IN UINT32 Type,
	IN EFI_TPL NotifyTpl,
	IN EFI_EVENT_NOTIFY NotifyFunction, OPTIONAL
	IN VOID *NotifyContext, OPTIONAL
	OUT EFI_EVENT *Event
	);

typedef struct {
	UINT32 Data1;
	UINT16 Data2;
	UINT16 Data3;
	UINT8 Data4[8];
} EFI_GUID;

typedef
EFI_STATUS
(EFIAPI *EFI_CREATE_EVENT_EX) (
	IN UINT32 Type,
	IN EFI_TPL NotifyTpl,
	IN EFI_EVENT_NOTIFY NotifyFunction OPTIONAL,
	IN CONST VOID *NotifyContext OPTIONAL,
	IN CONST EFI_GUID *EventGroup OPTIONAL,
	OUT EFI_EVENT *Event
	);

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_EVENT) (
	IN EFI_EVENT Event
	);

typedef
EFI_STATUS
(EFIAPI *EFI_SIGNAL_EVENT) (
	IN EFI_EVENT Event
	);

typedef
EFI_STATUS
(EFIAPI *EFI_WAIT_FOR_EVENT) (
	IN UINTN NumberOfEvents,
	IN EFI_EVENT *Event,
	OUT UINTN *Index
	);

typedef
EFI_STATUS
(EFIAPI *EFI_CHECK_EVENT) (
	IN EFI_EVENT Event
	);

typedef enum {
	TimerCancel,
	TimerPeriodic,
	TimerRelative
} EFI_TIMER_DELAY;

typedef
EFI_STATUS
(EFIAPI *EFI_SET_TIMER) (
	IN EFI_EVENT Event,
	IN EFI_TIMER_DELAY Type,
	IN UINT64 TriggerTime
	);

typedef
EFI_TPL
(EFIAPI *EFI_RAISE_TPL) (
	IN EFI_TPL NewTpl
	);

typedef
VOID
(EFIAPI *EFI_RESTORE_TPL) (
	IN EFI_TPL OldTpl
	);

typedef enum {
	AllocateAnyPages,
	AllocateMaxAddress,
	AllocateAddress,
	MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef enum {
	EfiReservedMemoryType,
	EfiLoaderCode,
	EfiLoaderData,
	EfiBootServicesCode,
	EfiBootServicesData,
	EfiRuntimeServicesCode,
	EfiRuntimeServicesData,
	EfiConventionalMemory,
	EfiUnusableMemory,
	EfiACPIReclaimMemory,
	EfiACPIMemoryNVS,
	EfiMemoryMappedIO,
	EfiMemoryMappedIOPortSpace,
	EfiPalCode,
	EfiPersistentMemory,
	EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef UINT64 EFI_PHYSICAL_ADDRESS;

typedef
EFI_STATUS
(EFIAPI *EFI_ALLOCATE_PAGES) (
	IN EFI_ALLOCATE_TYPE Type,
	IN EFI_MEMORY_TYPE MemoryType,
	IN UINTN Pages,
	IN OUT EFI_PHYSICAL_ADDRESS *Memory
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FREE_PAGES) (
	IN EFI_PHYSICAL_ADDRESS Memory,
	IN UINTN Pages
	);

typedef UINT64 EFI_VIRTUAL_ADDRESS;

typedef struct {
	UINT32 Type;
	EFI_PHYSICAL_ADDRESS PhysicalStart;
	EFI_VIRTUAL_ADDRESS VirtualStart;
	UINT64 NumberOfPages;
	UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

typedef
EFI_STATUS
(EFIAPI *EFI_GET_MEMORY_MAP) (
	IN OUT UINTN *MemoryMapSize,
	IN OUT EFI_MEMORY_DESCRIPTOR *MemoryMap,
	OUT UINTN *MapKey,
	OUT UINTN *DescriptorSize,
	OUT UINT32 *DescriptorVersion
	);

#define EFI_MEMORY_UC 0x0000000000000001
#define EFI_MEMORY_WC 0x0000000000000002
#define EFI_MEMORY_WT 0x0000000000000004
#define EFI_MEMORY_WB 0x0000000000000008
#define EFI_MEMORY_UCE 0x0000000000000010
#define EFI_MEMORY_WP 0x0000000000001000
#define EFI_MEMORY_RP 0x0000000000002000
#define EFI_MEMORY_XP 0x0000000000004000
#define EFI_MEMORY_NV 0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE 0x0000000000010000
#define EFI_MEMORY_RO 0x0000000000020000
#define EFI_MEMORY_RUNTIME 0x8000000000000000



#define EFI_MEMORY_DESCRIPTOR_VERSION 1

#define EFI_ACPI_20_TABLE_GUID \
{0x8868e871,0xe4f1,0x11d3,\
 {0xbc,0x22,0x00,0x80,0xc7,0x3c,0x88,0x81}}
#define ACPI_TABLE_GUID \
 {0xeb9d2d30,0x2d88,0x11d3,\
 {0x9a,0x16,0x00,0x90,0x27,0x3f,0xc1,0x4d}}
#define SAL_SYSTEM_TABLE_GUID \
 {0xeb9d2d32,0x2d88,0x11d3,\
 {0x9a,0x16,0x00,0x90,0x27,0x3f,0xc1,0x4d}}
#define SMBIOS_TABLE_GUID \
 {0xeb9d2d31,0x2d88,0x11d3,\
 {0x9a,0x16,0x00,0x90,0x27,0x3f,0xc1,0x4d}}
#define SMBIOS3_TABLE_GUID \
 {0xf2fd1544, 0x9794, 0x4a2c,\
 {0x99,0x2e,0xe5,0xbb,0xcf,0x20,0xe3,0x94})
#define MPS_TABLE_GUID \
 {0xeb9d2d2f,0x2d88,0x11d3,\
 {0x9a,0x16,0x00,0x90,0x27,0x3f,0xc1,0x4d}}
//
// ACPI 2.0 or newer tables should use EFI_ACPI_TABLE_GUID
//
#define EFI_ACPI_TABLE_GUID \
{0x8868e871,0xe4f1,0x11d3,\
{0xbc,0x22,0x00,0x80,0xc7,0x3c,0x88,0x81}}

#define ACPI_10_TABLE_GUID ACPI_TABLE_GUID

typedef struct {
	UINT64 Signature;
	UINT32 Revision;
	UINT32 HeaderSize;
	UINT32 CRC32;
	UINT32 Reserved;
} EFI_TABLE_HEADER;
typedef
EFI_STATUS
(EFIAPI *EFI_ALLOCATE_POOL) (
	IN EFI_MEMORY_TYPE PoolType,
	IN UINTN Size,
	OUT VOID **Buffer
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FREE_POOL) (
	IN VOID *Buffer
	);

typedef enum {
	EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

typedef VOID *EFI_HANDLE;

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_PROTOCOL_INTERFACE) (
	IN OUT EFI_HANDLE *Handle,
	IN EFI_GUID *Protocol,
	IN EFI_INTERFACE_TYPE InterfaceType,
	IN VOID *Interface
	);



typedef
EFI_STATUS
(EFIAPI *EFI_UNINSTALL_PROTOCOL_INTERFACE) (
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	IN VOID *Interface
	);

typedef
EFI_STATUS
(EFIAPI *EFI_REINSTALL_PROTOCOL_INTERFACE) (
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	IN VOID *OldInterface,
	IN VOID *NewInterface
	);

typedef
EFI_STATUS
(EFIAPI *EFI_REGISTER_PROTOCOL_NOTIFY) (
	IN EFI_GUID *Protocol,
	IN EFI_EVENT Event,
	OUT VOID **Registration
	);

typedef enum {
	AllHandles,
	ByRegisterNotify,
	ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE) (
	IN EFI_LOCATE_SEARCH_TYPE SearchType,
	IN EFI_GUID *Protocol OPTIONAL,
	IN VOID *SearchKey OPTIONAL,
	IN OUT UINTN *BufferSize,
	OUT EFI_HANDLE *Buffer
	);

typedef
EFI_STATUS
(EFIAPI *EFI_HANDLE_PROTOCOL) (
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	OUT VOID **Interface
	);

typedef struct _EFI_DEVICE_PATH_PROTOCOL {
	UINT8 Type;
	UINT8 SubType;
	UINT8 Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_DEVICE_PATH) (
	IN EFI_GUID *Protocol,
	IN OUT EFI_DEVICE_PATH_PROTOCOL **DevicePath,
	OUT EFI_HANDLE *Device
	);

#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL 0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL 0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL 0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER 0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER 0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE 0x00000020

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL) (
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	OUT VOID **Interface OPTIONAL,
	IN EFI_HANDLE AgentHandle,
	IN EFI_HANDLE ControllerHandle,
	IN UINT32 Attributes
	);

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_PROTOCOL) (
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	IN EFI_HANDLE AgentHandle,
	IN EFI_HANDLE ControllerHandle
	);

typedef struct {
	EFI_HANDLE AgentHandle;
	EFI_HANDLE ControllerHandle;
	UINT32 Attributes;
	UINT32 OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION) (
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer,
	OUT UINTN *EntryCount
	);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_MONOTONIC_COUNT) (
	OUT UINT64 *Count
	);

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_CONFIGURATION_TABLE) (
	IN EFI_GUID *Guid,
	IN VOID *Table
	);

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_LOAD) (
	IN BOOLEAN BootPolicy,
	IN EFI_HANDLE ParentImageHandle,
	IN EFI_DEVICE_PATH_PROTOCOL *DevicePath,
	IN VOID *SourceBuffer OPTIONAL,
	IN UINTN SourceSize,
	OUT EFI_HANDLE *ImageHandle
	);

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_START) (
	IN EFI_HANDLE ImageHandle,
	OUT UINTN *ExitDataSize,
	OUT CHAR16 **ExitData OPTIONAL
	);

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_UNLOAD) (
	IN EFI_HANDLE ImageHandle
	);

typedef struct EFI_SYSTEM_TABLE EFI_SYSTEM_TABLE;


typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_ENTRY_POINT) (
	IN EFI_HANDLE ImageHandle,
	IN EFI_SYSTEM_TABLE *SystemTable
	);

typedef
EFI_STATUS
(EFIAPI *EFI_EXIT) (
	IN EFI_HANDLE ImageHandle,
	IN EFI_STATUS ExitStatus,
	IN UINTN ExitDataSize,
	IN CHAR16 *ExitData OPTIONAL
	);

typedef
EFI_STATUS
(EFIAPI *EFI_EXIT_BOOT_SERVICES) (
	IN EFI_HANDLE ImageHandle,
	IN UINTN MapKey
	);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_WATCHDOG_TIMER) (
	IN UINTN Timeout,
	IN UINT64 WatchdogCode,
	IN UINTN DataSize,
	IN CHAR16 *WatchdogData OPTIONAL
	);


typedef
EFI_STATUS
(EFIAPI *EFI_STALL) (
	IN UINTN Microseconds
	);


typedef
EFI_STATUS
(EFIAPI *EFI_CONNECT_CONTROLLER) (
	IN EFI_HANDLE ControllerHandle,
	IN EFI_HANDLE *DriverImageHandle OPTIONAL,
	IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL,
	IN BOOLEAN Recursive
	);

typedef
EFI_STATUS
(EFIAPI *EFI_DISCONNECT_CONTROLLER) (
	IN EFI_HANDLE ControllerHandle,
	IN EFI_HANDLE DriverImageHandle OPTIONAL,
	IN EFI_HANDLE ChildHandle OPTIONAL
	);

typedef
EFI_STATUS
(EFIAPI *EFI_PROTOCOLS_PER_HANDLE) (
	IN EFI_HANDLE Handle,
	OUT EFI_GUID ***ProtocolBuffer,
	OUT UINTN *ProtocolBufferCount
	);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE_BUFFER) (
	IN EFI_LOCATE_SEARCH_TYPE SearchType,
	IN EFI_GUID *Protocol OPTIONAL,
	IN VOID *SearchKey OPTIONAL,
	IN OUT UINTN *NoHandles,
	OUT EFI_HANDLE **Buffer
	);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_PROTOCOL) (
	IN EFI_GUID *Protocol,
	IN VOID *Registration OPTIONAL,
	OUT VOID **Interface
	);

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
	IN OUT EFI_HANDLE *Handle,
	...
	);

typedef
EFI_STATUS
(EFIAPI *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
	IN EFI_HANDLE Handle,
	...
	);

typedef
VOID
(EFIAPI *EFI_COPY_MEM) (
	IN VOID *Destination,
	IN VOID *Source,
	IN UINTN Length
	);

typedef
VOID
(EFIAPI *EFI_SET_MEM) (
	IN VOID *Buffer,
	IN UINTN Size,
	IN UINT8 Value
	);

typedef
EFI_STATUS
(EFIAPI *EFI_CALCULATE_CRC32)(
	IN VOID *Data,
	IN UINTN DataSize,
	OUT UINT32 *Crc32
	);

typedef struct {
	EFI_TABLE_HEADER Hdr;
	//
	// Task Priority Services
	//
	EFI_RAISE_TPL RaiseTPL; // EFI 1.0+
	EFI_RESTORE_TPL RestoreTPL; // EFI 1.0+
								//
								// Memory Services
								//
	EFI_ALLOCATE_PAGES AllocatePages; // EFI 1.0+
	EFI_FREE_PAGES FreePages; // EFI 1.0+
	EFI_GET_MEMORY_MAP GetMemoryMap; // EFI 1.0+
	EFI_ALLOCATE_POOL AllocatePool; // EFI 1.0+
	EFI_FREE_POOL FreePool; // EFI 1.0+
							//
							// Event & Timer Services
							//
	EFI_CREATE_EVENT CreateEvent; // EFI 1.0+
	EFI_SET_TIMER SetTimer; // EFI 1.0+
	EFI_WAIT_FOR_EVENT WaitForEvent; // EFI 1.0+
	EFI_SIGNAL_EVENT SignalEvent; // EFI 1.0+
	EFI_CLOSE_EVENT CloseEvent; // EFI 1.0+
	EFI_CHECK_EVENT CheckEvent; // EFI 1.0+
								//
								// Protocol Handler Services
								//
	EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface; // EFI 1.0+
	EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface; // EFI 1.0+
	EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface; // EFI 1.0+
	EFI_HANDLE_PROTOCOL HandleProtocol; // EFI 1.0+
	VOID* Reserved; // EFI 1.0+
	EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify; // EFI 1.0+
	EFI_LOCATE_HANDLE LocateHandle; // EFI 1.0+
	EFI_LOCATE_DEVICE_PATH LocateDevicePath; // EFI 1.0+
	EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable; // EFI 1.0+
															   //
															   // Image Services
															   //
	EFI_IMAGE_LOAD LoadImage; // EFI 1.0+
	EFI_IMAGE_START StartImage; // EFI 1.0+
	EFI_EXIT Exit; // EFI 1.0+
	EFI_IMAGE_UNLOAD UnloadImage; // EFI 1.0+
	EFI_EXIT_BOOT_SERVICES ExitBootServices; // EFI 1.0+
											 //
											 // Miscellaneous Services
											 //
	EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount; // EFI 1.0+
	EFI_STALL Stall; // EFI 1.0+
	EFI_SET_WATCHDOG_TIMER SetWatchdogTimer; // EFI 1.0+
											 //
											 // DriverSupport Services
											 //
	EFI_CONNECT_CONTROLLER ConnectController; // EFI 1.1
	EFI_DISCONNECT_CONTROLLER DisconnectController;// EFI 1.1+
												   //
												   // Open and Close Protocol Services
												   //
	EFI_OPEN_PROTOCOL OpenProtocol; // EFI 1.1+
	EFI_CLOSE_PROTOCOL CloseProtocol; // EFI 1.1+
	EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation; // EFI 1.1+
														   //
														   // Library Services
														   //
	EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle; // EFI 1.1+
	EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer; // EFI 1.1+
	EFI_LOCATE_PROTOCOL LocateProtocol; // EFI 1.1+
	EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces; // EFI 1.1+
	EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES	UninstallMultipleProtocolInterfaces; // EFI 1.1+
											 //
											 // 32-bit CRC Services
											 //
	EFI_CALCULATE_CRC32 CalculateCrc32; // EFI 1.1+
										//
										// Miscellaneous Services
										//
	EFI_COPY_MEM CopyMem; // EFI 1.1+
	EFI_SET_MEM SetMem; // EFI 1.1+
	EFI_CREATE_EVENT_EX CreateEventEx; // UEFI 2.0+
} EFI_BOOT_SERVICES;

typedef struct {
	UINT32 Version;
	UINT32 Length;
	UINT64 MemoryProtectionAttribute;
} EFI_PROPERTIES_TABLE;

#define EFI_MEMORY_ATTRIBUTES_TABLE_GUID \
{ 0xdcfa911d, 0x26eb, 0x469f, \
 {0xa2, 0x20, 0x38, 0xb7, 0xdc, 0x46, 0x12, 0x20}}

typedef struct {
	UINT32 Version;
	UINT32 NumberOfEntries;
	UINT32 DescriptorSize;
	UINT32 Reserved;
	// EFI_MEMORY_DESCRIPTOR Entry [1];
} EFI_MEMORY_ATTRIBUTES_TABLE;

typedef struct EFI_TIME {
	UINT16 Year;
	UINT8 Month;
	UINT8 Day;
	UINT8 Hour;
	UINT8 Minute;
	UINT8 Second;
	UINT8 Pad1;
	UINT32 Nanosecond;
	INT16 TimeZone;
	UINT8 Daylight;
	UINT8 Pad2;
} EFI_TIME;

typedef struct {
	UINT32 Resolution;
	UINT32 Accuracy;
	BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

typedef EFI_STATUS(EFIAPI *EFI_GET_TIME)(OUT EFI_TIME *Time, OUT EFI_TIME_CAPABILITIES *Capabilities OPTIONAL);
typedef EFI_STATUS(EFIAPI *EFI_SET_TIME)(IN EFI_TIME *Time);
typedef EFI_STATUS(EFIAPI *EFI_GET_WAKEUP_TIME)(OUT BOOLEAN *Enabled, OUT BOOLEAN *Pending, OUT EFI_TIME *Time);
typedef EFI_STATUS(EFIAPI *EFI_SET_WAKEUP_TIME)(IN BOOLEAN Enable, IN EFI_TIME *Time OPTIONAL);

#define EFI_OPTIONAL_PTR 0x00000001

typedef EFI_STATUS(EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP)(IN UINTN MemoryMapSize, IN UINTN DescriptorSize, IN UINT32 DescriptorVersion, IN EFI_MEMORY_DESCRIPTOR *VirtualMap);
typedef EFI_STATUS(EFIAPI *EFI_CONVERT_POINTER)(IN UINTN DebugDisposition, IN VOID **Address);

typedef enum {
	EfiResetCold,
	EfiResetWarm,
	EfiResetShutdown,
	EfiResetPlatformSpecific
} EFI_RESET_TYPE;

typedef VOID(EFIAPI *EFI_RESET_SYSTEM)(IN EFI_RESET_TYPE ResetType, IN EFI_STATUS ResetStatus, IN UINTN DataSize, IN VOID *ResetData OPTIONAL);
typedef EFI_STATUS(EFIAPI *EFI_GET_NEXT_HIGH_MONO_COUNT)(OUT UINT32 *HighCount);

#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02
#define EFI_UNSPECIFIED_TIMEZONE 0x07FF

#define EFI_VARIABLE_NON_VOLATILE 0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS 0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS 0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD 0x00000008 
#define EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS 0x00000010
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS 0x00000020
#define EFI_VARIABLE_APPEND_WRITE 0x00000040

typedef EFI_STATUS(EFIAPI *EFI_GET_VARIABLE)(IN CHAR16 *VariableName, IN EFI_GUID *VendorGuid, OUT UINT32 *Attributes OPTIONAL, IN OUT UINTN *DataSize, OUT VOID *Data OPTIONAL);
typedef EFI_STATUS(EFIAPI *EFI_GET_NEXT_VARIABLE_NAME)(IN OUT UINTN *VariableNameSize, IN OUT CHAR16 *VariableName, IN OUT EFI_GUID *VendorGuid);
typedef EFI_STATUS(EFIAPI *EFI_SET_VARIABLE)(IN CHAR16 *VariableName, IN EFI_GUID *VendorGuid, IN UINT32 Attributes, IN UINTN DataSize, IN VOID *Data);
typedef EFI_STATUS(EFIAPI *EFI_QUERY_VARIABLE_INFO)(IN UINT32 Attributes, OUT UINT64 *MaximumVariableStorageSize, OUT UINT64 *RemainingVariableStorageSize, OUT UINT64 *MaximumVariableSize);

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

#define EFI_OS_INDICATIONS_BOOT_TO_FW_UI 0x0000000000000001
#define EFI_OS_INDICATIONS_TIMESTAMP_REVOCATION 0x0000000000000002
#define EFI_OS_INDICATIONS_FILE_CAPSULE_DELIVERY_SUPPORTED 0x0000000000000004
#define EFI_OS_INDICATIONS_FMP_CAPSULE_SUPPORTED 0x0000000000000008
#define EFI_OS_INDICATIONS_CAPSULE_RESULT_VAR_SUPPORTED 0x0000000000000010
#define EFI_OS_INDICATIONS_START_OS_RECOVERY 0x0000000000000020
#define EFI_OS_INDICATIONS_START_PLATFORM_RECOVERY 0x0000000000000040

typedef struct EFI_CAPSULE_BLOCK_DESCRIPTOR {
	UINT64 Length;
	union {
		EFI_PHYSICAL_ADDRESS DataBlock;
		EFI_PHYSICAL_ADDRESS ContinuationPointer;
	}Union;
} EFI_CAPSULE_BLOCK_DESCRIPTOR;

typedef struct EFI_CAPSULE_HEADER {
	EFI_GUID CapsuleGuid;
	UINT32 HeaderSize;
	UINT32 Flags;
	UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;


typedef EFI_STATUS(EFIAPI *EFI_UPDATE_CAPSULE)(IN EFI_CAPSULE_HEADER **CapsuleHeaderArray, IN UINTN CapsuleCount, IN EFI_PHYSICAL_ADDRESS ScatterGatherList OPTIONAL);
typedef EFI_STATUS(EFIAPI *EFI_QUERY_CAPSULE_CAPABILITIES)(IN EFI_CAPSULE_HEADER **CapsuleHeaderArray, IN UINTN CapsuleCount, OUT UINT64 *MaximumCapsuleSize, OUT EFI_RESET_TYPE *ResetType);

typedef struct {
	EFI_TABLE_HEADER Hdr;
	//
	// Time Services
	//
	EFI_GET_TIME GetTime;
	EFI_SET_TIME SetTime;
	EFI_GET_WAKEUP_TIME GetWakeupTime;
	EFI_SET_WAKEUP_TIME SetWakeupTime;
	//
	// Virtual Memory Services
	//
	EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
	EFI_CONVERT_POINTER ConvertPointer;
	//
	// Variable Services
	//
	EFI_GET_VARIABLE GetVariable;
	EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
	EFI_SET_VARIABLE SetVariable;
	//
	// Miscellaneous Services
	//
	EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
	EFI_RESET_SYSTEM ResetSystem;
	//
	// UEFI 2.0 Capsule Services
	//
	EFI_UPDATE_CAPSULE UpdateCapsule;
	EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;
	//
	// Miscellaneous UEFI 2.0 Service
	//
	EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
} EFI_RUNTIME_SERVICES;

typedef struct {
	EFI_GUID VendorGuid;
	VOID *VendorTable;
} EFI_CONFIGURATION_TABLE;

typedef struct {
	UINT16 ScanCode;
	CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID \
{0x387477c1,0x69c7,0x11d2,\
 {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

#define EFI_SCANCODE_HOME			0x05
#define EFI_SCANCODE_END			0x06
#define EFI_SCANCODE_INSERT			0X07
#define EFI_SCANCODE_DELETE			0x08
#define EFI_SCANCODE_PAGEUP			0x09
#define EFI_SCANCODE_PAGEDOWN		0x0A
#define EFI_SCANCODE_F1				0x0B
#define EFI_SCANCODE_F2				0x0C
#define EFI_SCANCODE_F3				0x0D
#define EFI_SCANCODE_F4				0x0E
#define EFI_SCANCODE_F5				0x0F
#define EFI_SCANCODE_F6				0x10
#define EFI_SCANCODE_F7				0x11
#define EFI_SCANCODE_F8				0x12
#define EFI_SCANCODE_F9 			0x13
#define EFI_SCANCODE_F10			0x14
#define EFI_SCANCODE_F10			0x15
#define EFI_SCANCODE_F10			0x16
#define EFI_SCANCODE_ESCAPE			0x17
#define EFI_SCANCODE_F13			0x68
#define EFI_SCANCODE_F13			0x69
#define EFI_SCANCODE_F13			0x6A
#define EFI_SCANCODE_F13			0x6B
#define EFI_SCANCODE_F13			0x6C
#define EFI_SCANCODE_F13			0x6D
#define EFI_SCANCODE_F13			0x6E
#define EFI_SCANCODE_F13			0x6F
#define EFI_SCANCODE_F13			0x70
#define EFI_SCANCODE_F13			0x71
#define EFI_SCANCODE_F13			0x72
#define EFI_SCANCODE_F13			0x73
#define EFI_SCANCODE_MUTE			0x7F
#define EFI_SCANCODE_VOLUMEUP		0x80
#define EFI_SCANCODE_VOLUMEDOWN		0x81
#define EFI_SCANCODE_BRIGHTNESSUP	0x100
#define EFI_SCANCODE_BRIGHTNESSDOWN	0x101
#define EFI_SCANCODE_SUSPEND		0x102
#define EFI_SCANCODE_HIBERNATE		0x103
#define EFI_SCANCODE_TOGGLEDISPLAY	0x104
#define EFI_SCANCODE_RECOVERY		0x105
#define EFI_SCANCODE_EJECT			0x106


typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_INPUT_READ_KEY) (
	IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
	OUT EFI_INPUT_KEY *Key
	);

typedef
EFI_STATUS
(EFIAPI *EFI_INPUT_RESET) (
	IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
	IN BOOLEAN ExtendedVerification
	);

typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
	EFI_INPUT_RESET Reset;
	EFI_INPUT_READ_KEY ReadKeyStroke;
	EFI_EVENT WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID \
 {0x387477c2,0x69c7,0x11d2,\
 {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct {
	INT32 MaxMode;
	// current settings
	INT32 Mode;
	INT32 Attribute;
	INT32 CursorColumn;
	INT32 CursorRow;
	BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_RESET) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN BOOLEAN ExtendedVerification
	);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_STRING) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN CHAR16 *String
	);

#define BOXDRAW_HORIZONTAL 0x2500
#define BOXDRAW_VERTICAL 0x2502
#define BOXDRAW_DOWN_RIGHT 0x250c
#define BOXDRAW_DOWN_LEFT 0x2510
#define BOXDRAW_UP_RIGHT 0x2514
#define BOXDRAW_UP_LEFT 0x2518
#define BOXDRAW_VERTICAL_RIGHT 0x251c
#define BOXDRAW_VERTICAL_LEFT 0x2524
#define BOXDRAW_DOWN_HORIZONTAL 0x252c
#define BOXDRAW_UP_HORIZONTAL 0x2534
#define BOXDRAW_VERTICAL_HORIZONTAL 0x253c
#define BOXDRAW_DOUBLE_HORIZONTAL 0x2550
#define BOXDRAW_DOUBLE_VERTICAL 0x2551
#define BOXDRAW_DOWN_RIGHT_DOUBLE 0x2552
#define BOXDRAW_DOWN_DOUBLE_RIGHT 0x2553
#define BOXDRAW_DOUBLE_DOWN_RIGHT 0x2554
#define BOXDRAW_DOWN_LEFT_DOUBLE 0x2555
#define BOXDRAW_DOWN_DOUBLE_LEFT 0x2556
#define BOXDRAW_DOUBLE_DOWN_LEFT 0x2557
#define BOXDRAW_UP_RIGHT_DOUBLE 0x2558
#define BOXDRAW_UP_DOUBLE_RIGHT 0x2559
#define BOXDRAW_DOUBLE_UP_RIGHT 0x255a
#define BOXDRAW_UP_LEFT_DOUBLE 0x255b
#define BOXDRAW_UP_DOUBLE_LEFT 0x255c
#define BOXDRAW_DOUBLE_UP_LEFT 0x255d
#define BOXDRAW_VERTICAL_RIGHT_DOUBLE 0x255e
#define BOXDRAW_VERTICAL_DOUBLE_RIGHT 0x255f
#define BOXDRAW_DOUBLE_VERTICAL_RIGHT 0x2560
#define BOXDRAW_VERTICAL_LEFT_DOUBLE 0x2561
#define BOXDRAW_VERTICAL_DOUBLE_LEFT 0x2562
#define BOXDRAW_DOUBLE_VERTICAL_LEFT 0x2563
#define BOXDRAW_DOWN_HORIZONTAL_DOUBLE 0x2564
#define BOXDRAW_DOWN_DOUBLE_HORIZONTAL 0x2565
#define BOXDRAW_DOUBLE_DOWN_HORIZONTAL 0x2566
#define BOXDRAW_UP_HORIZONTAL_DOUBLE 0x2567
#define BOXDRAW_UP_DOUBLE_HORIZONTAL 0x2568
#define BOXDRAW_DOUBLE_UP_HORIZONTAL 0x2569
#define BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE 0x256a
#define BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL 0x256b
#define BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL 0x256c
//*******************************************************
// EFI Required Block Elements Code Chart
//*******************************************************
#define BLOCKELEMENT_FULL_BLOCK 0x2588
#define BLOCKELEMENT_LIGHT_SHADE 0x2591
//*******************************************************
// EFI Required Geometric Shapes Code Chart
//*******************************************************
#define GEOMETRICSHAPE_UP_TRIANGLE 0x25b2
#define GEOMETRICSHAPE_RIGHT_TRIANGLE 0x25ba
#define GEOMETRICSHAPE_DOWN_TRIANGLE 0x25bc
#define GEOMETRICSHAPE_LEFT_TRIANGLE 0x25c4
//*******************************************************
// EFI Required Arrow shapes
//*******************************************************
#define ARROW_UP 0x2191
#define ARROW_DOWN 0x2193

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_TEST_STRING) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN CHAR16 *String
	);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_QUERY_MODE) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN UINTN ModeNumber,
	OUT UINTN *Columns,
	OUT UINTN *Rows
	);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_MODE) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN UINTN ModeNumber
	);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_ATTRIBUTE) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN UINTN Attribute
	);

#define EFI_BLACK 0x00
#define EFI_BLUE 0x01
#define EFI_GREEN 0x02
#define EFI_CYAN 0x03
#define EFI_RED 0x04
#define EFI_MAGENTA 0x05
#define EFI_BROWN 0x06
#define EFI_LIGHTGRAY 0x07
#define EFI_BRIGHT 0x08
#define EFI_DARKGRAY (EFI_BLACK | EFI_BRIGHT)
#define EFI_LIGHTBLUE 0x09
#define EFI_LIGHTGREEN 0x0A
#define EFI_LIGHTCYAN 0x0B
#define EFI_LIGHTRED 0x0C
#define EFI_LIGHTMAGENTA 0x0D
#define EFI_YELLOW 0x0E
#define EFI_WHITE 0x0F
#define EFI_BACKGROUND_BLACK 0x00
#define EFI_BACKGROUND_BLUE 0x10
#define EFI_BACKGROUND_GREEN 0x20
#define EFI_BACKGROUND_CYAN 0x30
#define EFI_BACKGROUND_RED 0x40
#define EFI_BACKGROUND_MAGENTA 0x50
#define EFI_BACKGROUND_BROWN 0x60
#define EFI_BACKGROUND_LIGHTGRAY 0x70
//
// Macro to accept color values in their raw form to create
// a value that represents both a foreground and background
// color in a single byte.
// For Foreground, and EFI_* value is valid from EFI_BLACK(0x00)
// to EFI_WHITE (0x0F).
// For Background, only EFI_BLACK, EFI_BLUE, EFI_GREEN,
// EFI_CYAN, EFI_RED, EFI_MAGENTA, EFI_BROWN, and EFI_LIGHTGRAY
// are acceptable.
//
// Do not use EFI_BACKGROUND_xxx values with this macro.
#define EFI_TEXT_ATTR(Foreground,Background) ((Foreground) | ((Background) << 4))

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_CLEAR_SCREEN) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This
	);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_CURSOR_POSITION) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN UINTN Column,
	IN UINTN Row
	);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_ENABLE_CURSOR) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN BOOLEAN Visible
	);

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
	EFI_TEXT_RESET Reset;
	EFI_TEXT_STRING OutputString;
	EFI_TEXT_TEST_STRING TestString;
	EFI_TEXT_QUERY_MODE QueryMode;
	EFI_TEXT_SET_MODE SetMode;
	EFI_TEXT_SET_ATTRIBUTE SetAttribute;
	EFI_TEXT_CLEAR_SCREEN ClearScreen;
	EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
	EFI_TEXT_ENABLE_CURSOR EnableCursor;
	SIMPLE_TEXT_OUTPUT_MODE *Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct EFI_SYSTEM_TABLE {
	EFI_TABLE_HEADER Hdr;
	CHAR16 *FirmwareVendor;
	UINT32 FirmwareRevision;
	EFI_HANDLE ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
	EFI_HANDLE ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
	EFI_HANDLE StandardErrorHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
	EFI_RUNTIME_SERVICES *RuntimeServices;
	EFI_BOOT_SERVICES *BootServices;
	UINTN NumberOfTableEntries;
	EFI_CONFIGURATION_TABLE *ConfigurationTable;
} EFI_SYSTEM_TABLE;

#define EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID \
 {0x9042a9de,0x23dc,0x4a38,\
 {0x96,0xfb,0x7a,0xde,0xd0,0x80,0x51,0x6a}}

typedef struct {
	UINT32 RedMask;
	UINT32 GreenMask;
	UINT32 BlueMask;
	UINT32 ReservedMask;
} EFI_PIXEL_BITMASK;

typedef enum {
	PixelRedGreenBlueReserved8BitPerColor,
	PixelBlueGreenRedReserved8BitPerColor,
	PixelBitMask,
	PixelBltOnly,
	PixelFormatMax
} EFI_GRAPHICS_PIXEL_FORMAT;

typedef struct {
	UINT32 Version;
	UINT32 HorizontalResolution;
	UINT32 VerticalResolution;
	EFI_GRAPHICS_PIXEL_FORMAT PixelFormat;
	EFI_PIXEL_BITMASK PixelInformation;
	UINT32 PixelsPerScanLine;
} EFI_GRAPHICS_OUTPUT_MODE_INFORMATION;

typedef struct {
	UINT32 MaxMode;
	UINT32 Mode;
	EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *Info;
	UINTN SizeOfInfo;
	EFI_PHYSICAL_ADDRESS FrameBufferBase;
	UINTN FrameBufferSize;
} EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE;
typedef struct EFI_GRAPHICS_OUTPUT_PROTOCOL EFI_GRAPHICS_OUTPUT_PROTOCOL;

typedef EFI_STATUS(EFIAPI *EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE) (IN EFI_GRAPHICS_OUTPUT_PROTOCOL *This, IN UINT32 ModeNumber, OUT UINTN *SizeOfInfo, OUT EFI_GRAPHICS_OUTPUT_MODE_INFORMATION **Info);

typedef
EFI_STATUS
(EFIAPI *EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE) (
	IN EFI_GRAPHICS_OUTPUT_PROTOCOL *This,
	IN UINT32 ModeNumber
	);

typedef struct {
	UINT8 Blue;
	UINT8 Green;
	UINT8 Red;
	UINT8 Reserved;
} EFI_GRAPHICS_OUTPUT_BLT_PIXEL;
typedef enum {
	EfiBltVideoFill,
	EfiBltVideoToBltBuffer,
	EfiBltBufferToVideo,
	EfiBltVideoToVideo,
	EfiGraphicsOutputBltOperationMax
} EFI_GRAPHICS_OUTPUT_BLT_OPERATION;

typedef
EFI_STATUS
(EFIAPI *EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT) (
	IN EFI_GRAPHICS_OUTPUT_PROTOCOL *This,
	IN OUT EFI_GRAPHICS_OUTPUT_BLT_PIXEL *BltBuffer, 
	OPTIONAL IN EFI_GRAPHICS_OUTPUT_BLT_OPERATION BltOperation,
	IN UINTN SourceX,
	IN UINTN SourceY,
	IN UINTN DestinationX,
	IN UINTN DestinationY,
	IN UINTN Width,
	IN UINTN Height,
	IN UINTN Delta
	);

typedef struct EFI_GRAPHICS_OUTPUT_PROTOCOL {
	EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE QueryMode;
	EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE SetMode;
	EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT Blt;
	EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *Mode;
} EFI_GRAPHICS_OUTPUT_PROTOCOL;

#define EFI_LOAD_FILE_PROTOCOL_GUID \
 {0x56EC3091,0x954C,0x11d2,\
 {0x8e,0x3f,0x00,0xa0, 0xc9,0x69,0x72,0x3b}}

typedef struct EFI_LOAD_FILE_PROTOCOL EFI_LOAD_FILE_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_LOAD_FILE) (
	IN EFI_LOAD_FILE_PROTOCOL *This,
	IN EFI_DEVICE_PATH_PROTOCOL *FilePath,
	IN BOOLEAN BootPolicy,
	IN OUT UINTN *BufferSize,
	IN VOID *Buffer OPTIONAL
	);

typedef struct EFI_LOAD_FILE_PROTOCOL {
	EFI_LOAD_FILE LoadFile;
} EFI_LOAD_FILE_PROTOCOL;

#define EFI_FILE_PROTOCOL_REVISION 0x00010000
#define EFI_FILE_PROTOCOL_REVISION2 0x00020000
#define EFI_FILE_PROTOCOL_LATEST_REVISION EFI_FILE_PROTOCOL_REVISION2

//*******************************************************
// Open Modes
//*******************************************************
#define EFI_FILE_MODE_READ 0x0000000000000001
#define EFI_FILE_MODE_WRITE 0x0000000000000002
#define EFI_FILE_MODE_CREATE 0x8000000000000000
//*******************************************************
// File Attributes
//*******************************************************
#define EFI_FILE_READ_ONLY 0x0000000000000001
#define EFI_FILE_HIDDEN 0x0000000000000002
#define EFI_FILE_SYSTEM 0x0000000000000004
#define EFI_FILE_RESERVED 0x0000000000000008
#define EFI_FILE_DIRECTORY 0x0000000000000010
#define EFI_FILE_ARCHIVE 0x0000000000000020
#define EFI_FILE_VALID_ATTR 0x0000000000000037

typedef struct EFI_FILE_PROTOCOL EFI_FILE_PROTOCOL;

typedef struct {
	EFI_EVENT Event;
	EFI_STATUS Status;
	UINTN BufferSize;
	VOID *Buffer;
} EFI_FILE_IO_TOKEN;

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_OPEN) (
	IN EFI_FILE_PROTOCOL *This,
	OUT EFI_FILE_PROTOCOL **NewHandle,
	IN CHAR16 *FileName,
	IN UINT64 OpenMode,
	IN UINT64 Attributes
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_CLOSE) (
	IN EFI_FILE_PROTOCOL *This
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_DELETE) (
	IN EFI_FILE_PROTOCOL *This
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_READ) (
	IN EFI_FILE_PROTOCOL *This,
	IN OUT UINTN *BufferSize,
	OUT VOID *Buffer
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_WRITE) (
	IN EFI_FILE_PROTOCOL *This,
	IN OUT UINTN *BufferSize,
	IN VOID *Buffer
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_OPEN_EX) (
	IN EFI_FILE_PROTOCOL *This,
	OUT EFI_FILE_PROTOCOL **NewHandle,
	IN CHAR16 *FileName,
	IN UINT64 OpenMode,
	IN UINT64 Attributes,
	IN OUT EFI_FILE_IO_TOKEN *Token
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_READ_EX) (
	IN EFI_FILE_PROTOCOL *This,
	IN OUT EFI_FILE_IO_TOKEN *Token
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_WRITE_EX) (	IN EFI_FILE_PROTOCOL *This,
	IN OUT EFI_FILE_IO_TOKEN *Token
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_FLUSH_EX) (
	IN EFI_FILE_PROTOCOL *This,
	IN OUT EFI_FILE_IO_TOKEN *Token
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_SET_POSITION) (
	IN EFI_FILE_PROTOCOL *This,
	IN UINT64 Position
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_GET_POSITION) (
	IN EFI_FILE_PROTOCOL *This,
	OUT UINT64 *Position
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_GET_INFO) (
	IN EFI_FILE_PROTOCOL *This,
	IN EFI_GUID *InformationType,
	IN OUT UINTN *BufferSize,
	OUT VOID *Buffer
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_SET_INFO) (
	IN EFI_FILE_PROTOCOL *This,
	IN EFI_GUID *InformationType,
	IN UINTN BufferSize,
	IN VOID *Buffer
	);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_FLUSH) (
	IN EFI_FILE_PROTOCOL *This
	);

typedef struct EFI_FILE_PROTOCOL {
	UINT64 Revision;
	EFI_FILE_OPEN Open;
	EFI_FILE_CLOSE Close;
	EFI_FILE_DELETE Delete;
	EFI_FILE_READ Read;
	EFI_FILE_WRITE Write;
	EFI_FILE_GET_POSITION GetPosition;
	EFI_FILE_SET_POSITION SetPosition;
	EFI_FILE_GET_INFO GetInfo;
	EFI_FILE_SET_INFO SetInfo;
	EFI_FILE_FLUSH Flush;
	EFI_FILE_OPEN_EX OpenEx; // Added for revision 2
	EFI_FILE_READ_EX ReadEx; // Added for revision 2
	EFI_FILE_WRITE_EX WriteEx; // Added for revision 2
	EFI_FILE_FLUSH_EX FlushEx; // Added for revision 2
} EFI_FILE_PROTOCOL;

#define EFI_FILE_INFO_ID \
 {0x09576e92,0x6d3f,0x11d2,\
 {0x8e39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

//*******************************************************
// File Attribute Bits
//*******************************************************

#define EFI_FILE_READ_ONLY 0x0000000000000001
#define EFI_FILE_HIDDEN 0x0000000000000002
#define EFI_FILE_SYSTEM 0x0000000000000004
#define EFI_FILE_RESERVED 0x0000000000000008
#define EFI_FILE_DIRECTORY 0x0000000000000010
#define EFI_FILE_ARCHIVE 0x0000000000000020
#define EFI_FILE_VALID_ATTR 0x0000000000000037

typedef struct {
	UINT64 Size;
	UINT64 FileSize;
	UINT64 PhysicalSize;
	EFI_TIME CreateTime;
	EFI_TIME LastAccessTime;
	EFI_TIME ModificationTime;
	UINT64 Attribute;
	CHAR16* FileName;
} EFI_FILE_INFO;

#define EFI_FILE_SYSTEM_INFO_ID \
 {0x09576e93,0x6d3f,0x11d2,0x8e39,0x00,0xa0,0xc9,0x69,0x72,\
 0x3b}

typedef struct {
	UINT64 Size;
	BOOLEAN ReadOnly;
	UINT64 VolumeSize;
	UINT64 FreeSpace;
	UINT32 BlockSize;
	CHAR16* VolumeLabel;
} EFI_FILE_SYSTEM_INFO;

#define EFI_FILE_SYSTEM_VOLUME_LABEL_ID \
{0xdb47d7d3,0xfe81,0x11d3,0x9a35,\
 {0x00,0x90,0x27,0x3f,0xC1,0x4d}}

typedef struct {
	CHAR16* VolumeLabel;
} EFI_FILE_SYSTEM_VOLUME_LABEL;


typedef UINT8* va_list;

#define va_size(x) sizeof(x)

#define va_start(list, arg) (list = ((va_list)&arg) + va_size(arg))
#define va_arg(list, type) (*(type*)((list += va_size(type)) - va_size(type)))
#define va_end(list) list = (va_list)0;

VOID InitializeLibrary(EFI_HANDLE handle, EFI_SYSTEM_TABLE* systable);

void* memset(void* dst, int v, unsigned long long size);
void* memcpy(void* dst, const void* src, unsigned long long size);
UINTN strlen(CONST CHAR16* CONST string);

VOID print(CONST CHAR16* CONST string);
VOID println(CONST CHAR16* CONST string);
VOID clearScreen();

VOID __cdecl printf(CONST CHAR16* CONST format, ...);
VOID __cdecl vprintf(CONST CHAR16* CONST format, va_list list);
UINTN __cdecl sprintf(CHAR16* CONST buffer, UINTN bufferSize, CONST CHAR16* CONST format, ...);
UINTN __cdecl vsprintf(CHAR16* CONST buffer, UINTN bufferSize, CONST CHAR16* CONST format, va_list list);
UINTN __cdecl fprintf(EFI_FILE_PROTOCOL* CONST file, CONST CHAR16* CONST format, ...);

UINT32 GetGraphicsMode(EFI_GRAPHICS_OUTPUT_PROTOCOL* CONST gop, UINT32* CONST width, UINT32* CONST height, EFI_GRAPHICS_PIXEL_FORMAT* CONST format);
UINTN GetTextMode(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* CONST text, UINTN* CONST columns, UINTN* CONST rows);

EFI_FILE_PROTOCOL* OpenFile(EFI_FILE_PROTOCOL* CONST root, CONST CHAR16* CONST filename, UINT64 openMode, UINT64 attributes);
VOID CloseFile(EFI_FILE_PROTOCOL* CONST file);
BOOLEAN DeleteFile(EFI_FILE_PROTOCOL* CONST file);
EFI_STATUS ReadFile(EFI_FILE_PROTOCOL* CONST file, UINTN* CONST size, VOID* CONST buffer);
EFI_STATUS WriteFile(EFI_FILE_PROTOCOL* CONST file, UINTN* CONST size, CONST VOID* CONST buffer);
EFI_STATUS SetPosition(EFI_FILE_PROTOCOL* CONST file, UINT64 position);
UINT64 GetPosition(EFI_FILE_PROTOCOL* CONST file);

VOID WaitEscapeAndExit();
