#include <stdio.h>
#include <string.h>

struct Item{
	char name[50];
	long int price;
}; 

long int change(long int a, long int b){
	long int result = a - b;
	
	return result;
}

long int totalOrder(long int a, long int b){
	long int result = a * b;
	
	return result;
}

int main(){
	
	int item, qty, choice2;
	long long int itemPrice, total = 0, finalTotal = 0, cash = 0;
	Item pilihan[3];
	
	FILE* fp1 = fopen("start.txt", "r"); // display lets get started text
	char startText;
	
	do{
		startText = getc(fp1);
		printf("%c", startText);
	}
	while(!feof(fp1));
		
	fclose(fp1);
	
	// assign values
	puts(" ");
	for(int i=0; i<3; i++){
		printf("Input the food's name: ");
		gets(pilihan[i].name);
		
		printf("Input food's price: ");
		scanf("%ld", &pilihan[i].price);
		getchar();
	}

	bool choose;
		
	do{
		system("cls"); // clear the output screen
		
		FILE* fp2 = fopen("mainMenu.txt", "r"); // display main menu text
		char menuText;
	
		do{
			menuText = getc(fp2);
			printf("%c", menuText);
		}
		while(!feof(fp2));
			
		
		printf("\n\n------------------------------------------------------------\n");
		printf("\tItems\t\t\t\tPrice\n");
		printf("------------------------------------------------------------\n");
		printf("1. | %s\t\t\tRp. %ld\n", pilihan[0].name, pilihan[0].price);
		printf("2. | %s\t\t\tRp. %ld\n", pilihan[1].name, pilihan[1].price);
		printf("3. | %s\t\t\tRp. %ld\n", pilihan[2].name, pilihan[2].price);
		printf("------------------------------------------------------------\n\n");
			
		printf("Enter the item's number = ");
		scanf("%d", &item);
		
		printf("Quantity = ");
		scanf("%d", &qty);	
		
		puts("\n------------------------------------------------------------\n");
		
		// calculate the amount of 1 order
		float amount = (float) totalOrder(pilihan[item-1].price, qty); // function
		
		printf("Total = Rp. %.1f\n", amount);
		//masukin total pembelian ke struk
		fprintf(fp2, "total biaya %d", total);
				
		// calculate the total of all order(s)
		finalTotal += (float)amount;
		printf("Total amount = Rp. %.1f\n", (float)finalTotal);
		
		printf("\nTake another order?\n"); // ask the user if they want to take another order
		printf("1. yes\n2. No\n");			// yes / no?
		getchar();
		printf("--> ");		
		scanf("%d", &choice2);
		getchar();

		choice2 == 2 ? choose = false : choose = true;
	}
	while(choose == true);

	puts("\n------------------------------------------------------------\n");
		
	char paymentMethod[10];
	puts("Choose payment method:");
	puts("- E-pay (30% discount!)");
	puts("- Cash");
	printf("--> ");
	scanf("%s", paymentMethod);
	
	puts("\n------------------------------------------------------------\n");
		
	printf("The total amount: Rp. %.1f\n", (float)finalTotal);
	
	float discount, afterDisc;
	
	if(strcmp(paymentMethod, "E-pay") == 0 || strcmp(paymentMethod, "e-pay") == 0){ // calculate after the discount
		discount = (float)finalTotal * 0.3;
		
		afterDisc = (float)finalTotal - discount;
		printf("The total amount: Rp. %.1f (after discount)\n", afterDisc);
	}
		
	puts("\n------------------------------------------------------------\n");
	
	printf("Enter the number of cash = Rp. "); // input the cash from the user
	scanf("%ld", &cash);
	getchar();
		
	// display the change
	if(strcmp(paymentMethod, "E-pay") == 0 || strcmp(paymentMethod, "e-pay") == 0){ // calculate after the discount
		while(cash < afterDisc){
			printf("Oh no! Try again!\n --> Rp. ");
			scanf("%ld", &cash);
			getchar();
		}
	
		puts("\n------------------------------------------------------------\n");
		
		long int result = (float)change(cash, afterDisc);
		
		switch(result){
			case 0:
				printf("No change!\n");
				break;
			default:
				printf("Here's your change! Rp. %ld\n", result);
				break;
		}
	}
	else{
		while(cash < finalTotal){
			printf("Oh no! Try again!\n --> Rp. ");
			scanf("%ld", &cash);
			getchar();
		}
		
		puts("\n------------------------------------------------------------\n");
	
		long int result = (float) change(cash, (float)finalTotal);
		
		switch(result){
			case 0:
				printf("No change!\n");
				break;
			default:
				printf("Here's your change! Rp. %ld\n", result);
				break;
		}
	}

	printf("Thank you and have a nice day! ;D");
	
	return 0;
}
