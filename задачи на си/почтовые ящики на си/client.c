#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
HANDLE hMailSlot;
DWORD Wrietit;
char Buffer[256];
BOOL Slot;	
	
hMailSlot = CreateFile("\\\\.\\mailslot\\mymailslot", GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
if (hMailSlot == INVALID_HANDLE_VALUE) 
{
    printf("CreateFile failed with %d\n", GetLastError());
    return 1;
}
    while(1)
    {
	printf("Enter a message:");
	scanf("%s", Buffer);
	
	Slot = WriteFile(hMailSlot, Buffer, sizeof(Buffer), &Wrietit, NULL);
	if (!Slot) 
	    {
		    printf("WriteFile failed with %d\n", GetLastError());
		    return 1;
	    }
    }
CloseHandle(hMailSlot);
 return 0;	
}