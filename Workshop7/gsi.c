//Marco Beltempo
//WorkShop 7 - Grocery Inventory

#include <stdio.h>

void clear (void);

int main(void){

long long int barcode[100];
int quantity[100], i;
double price[100], value[100], value1;
double total, value2;


                printf("Grocery Store Inventory\n");
                printf("=======================\n");

        for(i=0;i<100;i++){

                printf("Barcode   :  ");
			scanf("%lld", &barcode[i]);
				
			
        if (barcode[i]==0){

                break;

        }

                printf("Price     :  ");
                        scanf("%lf", &price[i]);
				

                printf("Quantity  :  ");
                        scanf("%d", &quantity[i]);
				
clear();
        }


                printf("\n             Goods in Stock\n");
                printf("             ==============\n\n");

                printf("Barcode    Price    Quantity    Value\n");

                printf("-------------------------------------\n");

        for(i=0;i<100 && barcode[i] !=0;i++){

	value[i] = quantity[i] * price[i];
	
		
	total = total + value[i];
        	printf("%lld  %.2lf          %d    %.2lf\n", barcode[i], price[i], quantity[i], value[i]);

}
		printf("                               ------\n");
	
		printf("Total value goods in stock      %.2lf\n", total);

	
}

void clear (void){

	char input = 0;
	while (input != '\n') 
	
	{
	input = getchar();
	}

}

