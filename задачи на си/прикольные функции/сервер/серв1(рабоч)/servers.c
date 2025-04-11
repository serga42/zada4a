#include <windows.h>
#include <stdio.h>

#define BUFSIZE 512


struct Tl{ //создание структуры
	unsigned uiBlock;
	unsigned uiStatus; 
	unsigned char szBuf[512];
	unsigned char szBuf2[512];
	unsigned char szBuf3[512];
};

int main()
{
	struct Tl Rec = {1,2,0,0,0}; 
int cli;
BOOL gogo;
HANDLE hpipe;
HANDLE hpipe2;
HANDLE hpipe3;
BOOL fConnected;
BOOL fConnected2;
BOOL fConnected3;
DWORD vgWrite ,vgRead;
DWORD vgWrite2 ,vgRead2;
DWORD vgWrite3 ,vgRead3;

//int buffer[225]={0};
//int buffer2[225]={0;
//int buffer3[225]={0};
//int buffer4[225]={0};

STARTUPINFO si;
PROCESS_INFORMATION pi;

ZeroMemory( &si, sizeof(si) );
si.cb = sizeof(si);
ZeroMemory( &pi, sizeof(pi) );


hpipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\Pipe"),
PIPE_ACCESS_DUPLEX,
PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
1,
512,
512,
NMPWAIT_USE_DEFAULT_WAIT,
NULL);

hpipe2 = CreateNamedPipe(TEXT("\\\\.\\pipe\\Pipee"),
PIPE_ACCESS_DUPLEX,
PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
1,
512,
512,
NMPWAIT_USE_DEFAULT_WAIT,
NULL);

hpipe3 = CreateNamedPipe(TEXT("\\\\.\\pipe\\Pipeee"),
PIPE_ACCESS_DUPLEX,
PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
1,
512,
512,
NMPWAIT_USE_DEFAULT_WAIT,
NULL);

if (hpipe == INVALID_HANDLE_VALUE)
{
printf("CreateNamedPipe failed, GLE=%d.\n", GetLastError());
return 0;
}

if (hpipe2 == INVALID_HANDLE_VALUE)
{
printf("CreateNamedPipe failed, GLE=%d.\n", GetLastError());
return 0;
}

if (hpipe3 == INVALID_HANDLE_VALUE)
{
printf("CreateNamedPipe failed, GLE=%d.\n", GetLastError());
return 0;
}



printf("Waiting for client connection...\n");	

gogo = CreateProcess( NULL, "egor.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );//ЕГОР//
fConnected = ConnectNamedPipe(hpipe, NULL); // Ожидаем соединения со стороны клиента
  if(!fConnected)
  {
    switch(GetLastError()) // При возникновении ошибки выводим ее код
    {
      case ERROR_NO_DATA:
        fprintf(stdout,"ConnectNamedPipe: ERROR_NO_DATA");
        getch();
        CloseHandle(hpipe);
        return 0;
      break;

      case ERROR_PIPE_CONNECTED:
        fprintf(stdout,
          "ConnectNamedPipe: ERROR_PIPE_CONNECTED");
        getch();
        CloseHandle(hpipe);
        return 0;
      break;

      case ERROR_PIPE_LISTENING:
        fprintf(stdout,
          "ConnectNamedPipe: ERROR_PIPE_LISTENING");
        getch();
        CloseHandle(hpipe);
        return 0;
      break;

      case ERROR_CALL_NOT_IMPLEMENTED:
        fprintf(stdout,
           "ConnectNamedPipe: ERROR_CALL_NOT_IMPLEMENTED");
        getch();
        CloseHandle(hpipe);
        return 0;
      break;

      default:
        fprintf(stdout,"ConnectNamedPipe: Error %ld\n", 
          GetLastError());
        getch();
        CloseHandle(hpipe);
        return 0;
      break;
    }
    CloseHandle(hpipe);
    getch();
    return 0;
  }
  
gogo = CreateProcess( NULL, "serga.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );//СЕРЕГА//
fConnected2 = ConnectNamedPipe(hpipe2, NULL); // Ожидаем соединения со стороны клиента
  if(!fConnected2)
  {
    switch(GetLastError()) // При возникновении ошибки выводим ее код
    {
      case ERROR_NO_DATA:
        fprintf(stdout,"ConnectNamedPipe: ERROR_NO_DATA");
        getch();
        CloseHandle(hpipe2);
        return 0;
      break;

      case ERROR_PIPE_CONNECTED:
        fprintf(stdout,
          "ConnectNamedPipe: ERROR_PIPE_CONNECTED");
        getch();
        CloseHandle(hpipe2);
        return 0;
      break;

      case ERROR_PIPE_LISTENING:
        fprintf(stdout,
          "ConnectNamedPipe: ERROR_PIPE_LISTENING");
        getch();
        CloseHandle(hpipe2);
        return 0;
      break;

      case ERROR_CALL_NOT_IMPLEMENTED:
        fprintf(stdout,
           "ConnectNamedPipe: ERROR_CALL_NOT_IMPLEMENTED");
        getch();
        CloseHandle(hpipe2);
        return 0;
      break;

      default:
        fprintf(stdout,"ConnectNamedPipe: Error %ld\n", 
          GetLastError());
        getch();
        CloseHandle(hpipe2);
        return 0;
      break;
    }
    CloseHandle(hpipe2);
    getch();
    return 0;
  }
gogo = CreateProcess( NULL, "MrBeast.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );//МрБИСТ
fConnected3 = ConnectNamedPipe(hpipe3, NULL); // Ожидаем соединения со стороны клиента
  if(!fConnected3)
  {
    switch(GetLastError()) // При возникновении ошибки выводим ее код
    {
      case ERROR_NO_DATA:
        fprintf(stdout,"ConnectNamedPipe: ERROR_NO_DATA");
        getch();
        CloseHandle(hpipe3);
        return 0;
      break;

      case ERROR_PIPE_CONNECTED:
        fprintf(stdout,
          "ConnectNamedPipe: ERROR_PIPE_CONNECTED");
        getch();
        CloseHandle(hpipe3);
        return 0;
      break;

      case ERROR_PIPE_LISTENING:
        fprintf(stdout,
          "ConnectNamedPipe: ERROR_PIPE_LISTENING");
        getch();
        CloseHandle(hpipe3);
        return 0;
      break;

      case ERROR_CALL_NOT_IMPLEMENTED:
        fprintf(stdout,
           "ConnectNamedPipe: ERROR_CALL_NOT_IMPLEMENTED");
        getch();
        CloseHandle(hpipe3);
        return 0;
      break;

      default:
        fprintf(stdout,"ConnectNamedPipe: Error %ld\n", 
          GetLastError());
        getch();
        CloseHandle(hpipe3);
        return 0;
      break;

    }

    CloseHandle(hpipe3);
    getch();
    return 0;
  }
  
while(1)
{
	if(ReadFile(hpipe, Rec.szBuf, 512, &vgRead, NULL))//если от егора приходит сообщение
	{
	printf("egor chat server=%s\n", Rec.szBuf);
	WriteFile(hpipe2, Rec.szBuf, strlen(Rec.szBuf) + 1,&vgWrite2, NULL);
	WriteFile(hpipe3, Rec.szBuf, strlen(Rec.szBuf) + 1,&vgWrite3, NULL);
    }
	
	if(ReadFile(hpipe2, Rec.szBuf2, 512, &vgRead2, NULL))//если от сережи приходит сообщение
	{
	printf("serega%s\n", Rec.szBuf2);
	WriteFile(hpipe, Rec.szBuf2, strlen(Rec.szBuf) + 1,&vgWrite, NULL);
	WriteFile(hpipe3, Rec.szBuf2, strlen(Rec.szBuf3) + 1,&vgWrite3, NULL);
	}
	
	if(ReadFile(hpipe3, Rec.szBuf3, 512, &vgRead3, NULL))//если от биста приходит сообщение
	{
	printf("MrBeast%s", Rec.szBuf3);
	WriteFile(hpipe, Rec.szBuf3, strlen(Rec.szBuf) + 1,&vgWrite, NULL);
	WriteFile(hpipe2, Rec.szBuf3, strlen(Rec.szBuf3) + 1,&vgWrite2, NULL);
	}
}

printf("Client connected, reading request...\n");

//ReadFile(hpipe, szBuf, 512, &vgRead, NULL);	
	
//printf("Received: <%s>\n", szBuf);
	
	
	
	
	
	
	
CloseHandle(hpipe);
CloseHandle(hpipe2);
CloseHandle(hpipe3);
	
return 0;
}