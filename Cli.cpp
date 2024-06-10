    // ----[includes]---- // 

#include <iostream>
#include <windows.h>

// ----[defines]---- //
#define MAX_PATH 29

class Process { 

    public: 

         void injection() {
            
    // make the process run in the background
    PROCESS_INFORMATION pi;
    //  Startup the process and make that start from zero 0 
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    // Create the command line text for the process
    TCHAR commandline[MAX_PATH] = TEXT("C:\\Windows\\System32\\calc.exe");
    // Create the process as a bool which I can simpfly the code
    auto Process = CreateProcess(
        NULL,        // No module name (use command line)
        commandline, // Command line
        NULL,        // Process handle not inheritable
        NULL,        // Thread handle not inheritable
        FALSE,       // Set handle inheritance to FALSE
        NULL,        // No creation flags
        NULL,        // Use parent's environment block
        NULL,        // Use parent's starting directory
        &si,         // Start up info
        &pi);        // Process information
    //  if that process failed to execute 
    if (!Process)
    {
        std::cout << "[-] failed to make the process" << "\n" << GetLastError() << std::endl;
    }
    // if the process is successed to create
    else {
    std::cout << "[+] successed to create process " << "\n" << std::endl;

    }

    //  wait for that process to end
    WaitForSingleObject(pi.hProcess, INFINITE);

    //  close the process
    CloseHandle(pi.hProcess);
    //  close the thread 
    CloseHandle(pi.hThread);
            
        }
};


int main(void)
{

    Process pro;
    pro.injection();
    return 0;

}
