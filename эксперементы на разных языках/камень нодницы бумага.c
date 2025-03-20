#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char u, char computer){
	if(u == computer){
	return -1;
    }
    // r - rock, s - scissors, p - paper//
    if (u == 'r' && computer == 'p'){
    	return 0;
	}
	
	else if (u == 'p' && computer == 'r'){
		return 1;
	}
	
	if (u == 'r' && computer == 's'){
		return 1;
	}
	
	else if (u == 's' && computer == 'r'){
		return 0;
	}
	
	if (u == 'p' && computer == 's'){
		return 0;
	}
	
	else if (u = 's' && computer == 'p'){
		return 1;
	}
}

int main() {
	STARTUPINFO si = {sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;
	int i;
	char u, computer, res;
	srand(time(NULL));
	i = rand() % 100;
	if(i < 33){
		computer = 'r';
	}
	
	else if (i > 33 && i < 66){
		computer = 's';
	}
	
	if (i > 66){
		computer = 'p';
	}
	printf("r - rock\n");
	printf("s - scissor\n");
	printf("p - paper\n");
	printf("Enter the character:");
	scanf("%c", &u); 
	res = game(u, computer);
	
	if (res == -1){
		printf("Nobody won in this game\n");
		printf("You choose: %c and computer choose: %c\n", u, computer);
	}
	
	else if (res == 1){
		printf("Great! You won\n");
		printf("You choose: %c and computer choose: %c\n", u, computer);
		if(CreateProcess(NULL, "G:\\first work\\fractions.exe", NULL, NULL, FALSE,0 , NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
} else {
    }
	}
	
	else {
		printf("You lose. You can try again\n");
		printf("You choose: %c and computer choose: %c\n", u, computer);
		
	}
    return 1;
}