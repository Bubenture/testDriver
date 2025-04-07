#include <ntddk.h> 


NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING RegistryPath);
NTSTATUS DriverUnload(PDRIVER_OBJECT pDriverObject);
VOID PrintSystemInformation();


NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING RegistryPath) { 
    DbgPrintEx(0, 0, "Hello world!\n");

   
    PrintSystemInformation(); 

    
    pDriverObject->DriverUnload = DriverUnload; 
    return STATUS_SUCCESS; 
}

NTSTATUS DriverUnload(PDRIVER_OBJECT pDriverObject) {
   
    DbgPrintEx(0, 0, "Goodbye!\n");

    return STATUS_SUCCESS;
}

VOID PrintSystemInformation() { /
    RTL_OSVERSIONINFOW versionInfo;
    versionInfo.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOW);

    if (NT_SUCCESS(RtlGetVersion(&versionInfo))) {
        DbgPrintEx(0, 0, "Operating System Version: %d.%d.%d\n", versionInfo.dwMajorVersion, versionInfo.dwMinorVersion, versionInfo.dwBuildNumber);
    }
    else {
        DbgPrintEx(0, 0, "Failed to retrieve operating system version\n");
    }
}
