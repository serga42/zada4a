#include <stdio.h>

int main(int argc, char** argv) {
	char name[50];
	char author[50];
	int year;
	int ISBN;
	printf("Enter name of the book: ");
	scanf("%s", &name);
	printf("Enter author: ");
	scanf("%s", &author);
	printf("Enter year: ");
	scanf("%d", &year);
	printf("Enter ISBN: ");
	scanf("%d", &ISBN);
	
	printf("\n");
	printf("\"%s\"\n", name);
	printf("\"%s\"\n", author);
	printf("%d\n", year);
	printf("%d", ISBN);
	return 0;
}