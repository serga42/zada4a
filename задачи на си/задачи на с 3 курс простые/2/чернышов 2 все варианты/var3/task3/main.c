#include <stdio.h>

int main(int argc, char** argv) {
	char product[50];
	char country[50];
	int amount;
	float price;
	printf("Enter product: ");
	scanf("%s", &product);
	printf("Vvedi country: ");
	scanf("%s", &country);
	printf("Enter price: ");
	scanf("%f", &price);
	printf("Enter amount: ");
	scanf("%d", &amount);
	
	
	printf("\n\t****\n");
	printf("Product: \"%s\"\n", product);
	printf("Country: %s\n", country);
	printf("Price: %.2f\n", price);
	printf("Amount: %d\n", amount);
	printf("Total: %.2f\n", (float)amount*price);
	
	return 0;
}
