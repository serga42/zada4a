#include <stdio.h>

int main(int argc, char** argv) {
	char name[20];
	char surname[20];
	int age;
	char hobby[50];
	printf("Enter name: ");
	scanf("%s", &name);
	printf("Enter surname: ");
	scanf("%s", &surname);
	printf("Enter age: ");
	scanf("%d", &age);
	printf("Enter hobby: ");
	scanf("%s", &hobby);
	
	printf("\n");
	printf("\"%s\"\t", name);
	printf("\"%s\"\t", surname);
	printf("%d\t", age);
	printf("%s", hobby);
	return 0;
}