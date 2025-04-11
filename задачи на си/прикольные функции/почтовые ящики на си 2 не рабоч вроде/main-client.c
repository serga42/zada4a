#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
	STARTUPINFO si = {sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;
    si.cb = sizeof(si);
    
    int a;
    HANDLE hMailSlot;
    DWORD dwBytesWritten;
    char Buffer[256];
    BOOL Slot;
    printf("What u do?\n");
    printf("1) Write a message\n");
    printf("2) View the archive of messages\n");
    printf("Enter a number here:");
    scanf("%d", &a);
    switch(a)
{
    	case 1:
    if(CreateProcess(NULL, "notepad.exe D:\\MainSlots\\FirstClient\\MailofFirstClient.txt", NULL, NULL, FALSE,0 , NULL, NULL, &si, &pi)) 
	{
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);  
    }
    break;
    
    case 2:
    hMailSlot = CreateFile("\\\\.\\mailslot\\mymailslot", GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hMailSlot == INVALID_HANDLE_VALUE) 
    {
        printf("CreateFile failed with %d\n", GetLastError());
        return 1;
    }
    while (1)
    {
        printf("Enter a message:");
	    scanf("%s", Buffer);
	
 	    Slot = WriteFile(hMailSlot, Buffer, sizeof(Buffer), &dwBytesWritten, NULL);
	    if (!Slot) 
	    {
		    printf("WriteFile failed with %d\n", GetLastError());
		    return 1;
	    }
    }
    CloseHandle(hMailSlot);
    break;
    
    	default:
    		printf("an incorrectly entered number\n");
}
getchar();
    return 0;
}