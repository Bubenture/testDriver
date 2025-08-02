### The program is a simple driver for the Windows operating system, written in C.

</br>
<div>
    <a href="README.md">
        <img src="https://img.shields.io/badge/README-RU-blue?color=006400&labelColor=006400&style=for-the-badge">
    </a>
    <a href="README.en.md">
        <img src="https://img.shields.io/badge/README-ENG-blue?color=44944a&labelColor=1C2325&style=for-the-badge">
    </a>
</div>
</br>

#### Main Components of the Program

##### Header Files:
- `#include <ntddk.h>`: This header file includes definitions and functions necessary for driver development in Windows.

##### Functions:
- `DriverEntry`: The main initialization function of the driver.
- `DriverUnload`: The function called when the driver is unloaded.
- `PrintSystemInformation`: A function to retrieve and display information about the operating system version.

#### Logic of Operation

##### DriverEntry:
- This function is called when the driver is loaded. It takes two parameters: a pointer to the driver object (`PDRIVER_OBJECT pDriverObject`) and a pointer to the registry string (`PUNICODE_STRING RegistryPath`).
- Inside the function, a message "Hello world!" is output to the debug output using `DbgPrintEx`.
- Then, the `PrintSystemInformation` function is called, which outputs information about the operating system version.
- At the end of the function, a pointer to the driver unload function (`DriverUnload`) is set.

##### DriverUnload:
- This function is called when the driver is unloaded. It also outputs a message "Goodbye!" to the debug output.
- It returns the status `STATUS_SUCCESS`, indicating successful completion.

##### PrintSystemInformation:
- This function creates a structure `RTL_OSVERSIONINFOW`, which is used to store information about the operating system version.
- The `RtlGetVersion` function is used to query the OS version. If the request is successful, version information (major version, minor version, and build number) is displayed.
- If the request fails, an error message is output.
