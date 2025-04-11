#include <windows.h>
#include <stdio.h>

int main() 
{
	HANDLE hMailSlot;
    DWORD dwBytesRead;
    char Buffer[256];
    BOOL Slot;

    FILE *Mail;
        Mail = fopen("D:\\MainSlots\\FirstClient\\MailofFirstClient.txt", "a");
        	hMailSlot = CreateMailslot("\\\\.\\mailslot\\mymailslot", 0, MAILSLOT_WAIT_FOREVER, NULL);
        if (hMailSlot == INVALID_HANDLE_VALUE) 
        {
	        printf("CreateMailslot failed with %d\n", GetLastError());
	        return 1;
        }
        while(1)
        {
        Slot = ReadFile(hMailSlot, Buffer, sizeof(Buffer), &dwBytesRead, NULL);
	    if (!Slot) 
	    {
		    printf("ReadFile failed with %d\n", GetLastError());
		    CloseHandle(hMailSlot);
		    return 1;
	    }
	    printf("Received message: %s\n", Buffer);
	        fprintf(Mail, "%s\n", Buffer); 
	    } 
	fclose(Mail);
    CloseHandle(hMailSlot);
    return 0;
}