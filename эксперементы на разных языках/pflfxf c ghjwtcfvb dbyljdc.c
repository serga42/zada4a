#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void main( int argc, TCHAR *argv[] )
{
	int  russia , USA, China, Japan, Germany;
	int Moscow,  Washington, Beijing, Tokyo, Berlin, ris;
	int a = 1, b = 2, c = 3;
	STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
	
	
	
	printf("what is the capital of this country?\n");
	printf("russia\n");
	printf("answer options:\n");
	printf("1)Moscow\n");
	printf("2)Washington\n");
	printf("3)Beijing\n");
	printf("4)Tokyo\n");
	printf("5)Berlin\n");
	printf("answer:");
	scanf("%d, &ris");	

    if(ris == a)
	
    	 if( !CreateProcess( NULL,"notepad.exe",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi )) 
    {
        printf( "CreateProcess failed (%d).\n", GetLastError() );
        return;
    }
    		
	
	
	
	WaitForSingleObject( pi.hProcess, INFINITE );

	
   CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );



}