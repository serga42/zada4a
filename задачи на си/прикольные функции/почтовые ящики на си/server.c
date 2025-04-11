#include <windows.h>
#include <stdio.h>

	struct Tl{ //создание структуры
	unsigned char Buffer[256];
	unsigned char Bufferr[256];
};
    HANDLE hMailSlot;
	DWORD Readit, Wrietit;
	BOOL Slot;
	



int main()
{
STARTUPINFO si;
PROCESS_INFORMATION pi;

ZeroMemory( &si, sizeof(si) );
si.cb = sizeof(si);
ZeroMemory( &pi, sizeof(pi) );

struct Tl Rec = {1,2,0,0,0}; 
	
	FILE *Mail4len;
    	Mail4len = fopen("bzpenis.txt", "a");
	    hMailSlot = CreateMailslot("\\\\.\\mailslot\\mymailslot", 0, MAILSLOT_WAIT_FOREVER, NULL);
	     if (hMailSlot == INVALID_HANDLE_VALUE) 
        {
	        printf("CreateMailslot failed with %d\n", GetLastError());
	        return 1;
        }
        CreateProcess( NULL, "client.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );
        CreateProcess( NULL, "client-macs.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );
    while(1)
    {
        Slot = ReadFile(hMailSlot, Rec.Buffer, 512, &Readit, NULL);
	    if (!Slot) 
	    {
		printf("ReadFile failed with %d\n", GetLastError());
		CloseHandle(hMailSlot);
		return 1;
	    }
	    printf("Received message: %s\n", Rec.Buffer);
	    fprintf(Mail4len, "pc<%s>\n", Rec.Buffer); 
	     printf("the server recorded: %s\n", Rec.Buffer);
	     
	     
	     
        Slot = ReadFile(hMailSlot, Rec.Bufferr, 512, &Readit, NULL);
	    if (!Slot) 
	    {
		printf("ReadFile failed with %d\n", GetLastError());
		CloseHandle(hMailSlot);
		return 1;
	    }
	    printf("Received message: %s\n", Rec.Bufferr);
	    fprintf(Mail4len, "2pc<%s>\n", Rec.Bufferr); 
	     printf("the server recorded: %s\n", Rec.Bufferr);
	}
		
	fclose(Mail4len);
	CloseHandle(hMailSlot);
    return 0;
}
