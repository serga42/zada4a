#include <windows.h>
#include <stdio.h>

#define BUFSIZE 512

int main()
{
int cli;
HANDLE gogo;
HANDLE hpipe;
HANDLE hpipe2;
HANDLE hpipe3;
BOOL fConnected;
char   szBuf[512];
char   szBuff[512];
char   szBufff[512];
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
printf("open  chat\n1)egor\n2)serega\n3)MrBeast\n4) all\n");
scanf("%d", &cli);
	switch(cli)
	{
case 1:
	gogo = CreateProcess( NULL, "egor.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );
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
    printf("Connect client-egor\n");
    ReadFile(hpipe, szBuf, 512, &vgRead, NULL);
    printf("Received: <%s>\n", szBuf);
	break;
	
case 2:
	gogo = CreateProcess( NULL, "serga.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );
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
    printf("Connect client-serega\n");
    ReadFile(hpipe2, szBuff, 512, &vgRead2, NULL);
    printf("Received: <%s>\n", szBuff);
	break;
	
case 3:
	gogo = CreateProcess( NULL, "MrBeast.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );
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
    printf("Connect client-MrBeast\n");
    ReadFile(hpipe3, szBufff, 512, &vgRead3, NULL);
    printf("Received: <%s>\n", szBufff);
	break;
	
case 4:
	gogo = CreateProcess( NULL, "egor.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );
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
    printf("Connect client-egor\n");
		        
	gogo = CreateProcess( NULL, "serga.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );
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
    printf("Connect client-serega\n");
        
	gogo = CreateProcess( NULL, "MrBeast.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi );
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
    printf("Connect client-MrBeast\n");
        
        
        
    ReadFile(hpipe, szBuf, 512, &vgRead, NULL);
    printf("egor-Received: <%s>\n", szBuf);
        
    ReadFile(hpipe2, szBuff, 512, &vgRead2, NULL);
    printf("serega-Received: <%s>\n", szBuff);
        
    ReadFile(hpipe3, szBufff, 512, &vgRead3, NULL);
    printf("MrBeast-Received: <%s>\n", szBufff);
	break;
	}

printf("Client connected, reading request...\n");

//ReadFile(hpipe, szBuf, 512, &vgRead, NULL);	
	
//printf("Received: <%s>\n", szBuf);
	
	
	
	
	
	
	
CloseHandle(hpipe);
CloseHandle(hpipe2);
CloseHandle(hpipe3);
	
return 0;
}