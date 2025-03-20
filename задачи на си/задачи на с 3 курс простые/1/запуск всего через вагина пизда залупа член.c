#include <stdio.h>
#include <windows.h>

int main(){
	STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
	char variant;
	printf("введите вариант");
	variant = getchar();
	switch(variant){
	case '1':
			if( !CreateProcess( NULL, "sd1.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi )          
	    ) 
	    {
	        printf( "CreateProcess failed (%d).\n", GetLastError() );
	        return;
	    }
			break;
			
	case '2':
			if( !CreateProcess( NULL, "sd2.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi )          
	    ) 
	    {
	        printf( "CreateProcess failed (%d).\n", GetLastError() );
	        return;
	    }
			break;
			
	case '3':
			if( !CreateProcess( NULL, "sd3.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi )          
	    ) 
	    {
	        printf( "CreateProcess failed (%d).\n", GetLastError() );
	        return;
	    }
			break;
			
	case '4':
			if( !CreateProcess( NULL, "sd4.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi )          
	    ) 
	    {
	        printf( "CreateProcess failed (%d).\n", GetLastError() );
	        return;
	    }
			break;
}
return 0;
}
