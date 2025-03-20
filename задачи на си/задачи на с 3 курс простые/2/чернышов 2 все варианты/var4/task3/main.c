#include <stdio.h>

int main() {
    char street[50], house_number[50], city[50], country[50], postal_code[50];

    printf("Enter street: ");
    scanf("%s", street);
    printf("Enter house number: ");
    scanf("%s", house_number);
    printf("Enter city: ");
    scanf("%s", city);
    printf("Enter country: ");
    scanf("%s", country);
    printf("Enter postal code: ");
    scanf("%s", postal_code);

    printf("\n\t\tPostal Address:\n\n");
    printf("\t%s %s\n", street, house_number);  
    printf("\t%s\n", city);                    
    printf("\t%s\n", country);                 
    printf("\t%s\n", postal_code);              

    return 0;
}