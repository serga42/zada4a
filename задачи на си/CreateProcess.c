#include <windows.h>
#include <stdio.h>
//запуск .exe файла

void main( int argc, TCHAR *argv[] )
{
	int b, a, x, f;
	
	STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
	Q:
	M:
	C:
	printf("\nrun the program??\n");	
	printf("1)YeS\n");
	printf("2)no\n");
	printf("answer:");
	scanf("%d", &a);	
	
	if(a==46){
		sleep(3);
		printf("you found a secret\n");
		sleep(2);
		printf("do you think you're cool?\n");
		sleep(2);
		printf("1)no\n");
		printf("2)no\n");
		scanf("%d", &x);
		sleep(2);
		printf("wawawawa know your place\n");
		sleep(3);
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
		sleep(5);
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) -1);
		return;
		}
	

  	if(a==2)
	{
	printf("\nnare you sure?");
	printf("\n1)Yes \n2)No\n");
	scanf("%d", &f);
	
	if(f==1)
	{
    return 0;
	}
	if(f==2)
	{printf("return,,");
	goto M;
	}
	}
	  
  	 if(a==1)
	{
  	 	printf("\ncontinue in this one or open a new console?\n");
  	 	printf("1)continue with this\n");
  	 	printf("2)open in new window\n");
  	 	printf("3)back\n");
  	 	printf("answer:");
  	 	scanf("%d", &b);
  	 	
  	if(b==1)
    	 {
    if( !CreateProcess( NULL, "sp.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi )          
	    ) 
	    {
	        printf( "CreateProcess failed (%d).\n", GetLastError() );
	        return;
	    }
	}
	
	if(b==2)
    {
    if( !CreateProcess( NULL, "sp.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi )          
	    ) 
	    {
	        printf( "CreateProcess failed (%d).\n", GetLastError() );
	        return;
	    }
	}
	if(b==3)
	goto C;
    }

	
   CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}