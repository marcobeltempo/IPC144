// Marco Beltempo - 9/21/15
// Part B- Computations Workshop 2
// Point of Sale Calculator

// Variables
// # of tiems
// Unit price
// Purchase price
// HST - Defined @ 0.13
// Total Price
// Cash Tendered
// Change in loonies
// Change in cents 

#include <stdio.h>

 int main (void)

 {

//Variables
 
	float no_items;
	float unit_price;
	float purchase_price;
	float total_price = 0.0;
	float cash_tendered = 0.0;
	float hst = 0.13;
	int loonies = 1;
	float cents = 0.01;

// Prompt the user to enter number of items
// Copy the users response to a no_items
       
	 printf("Enter the number of items : ");
         scanf("%f", &no_items);
 
// Prompt the user to enter the purchase price
// Copy the ursers reponse to unit_price
        
	printf("Enter the unit price : ");
        scanf("%f", &unit_price);

// Multiply the no_items  * unit_price

        purchase_price = no_items * unit_price;

// Display the purchase price

        printf("Purchase price %.2f\n",purchase_price);

// Calculate the HST 13%

	hst = purchase_price * hst;
	
// Display the HST

	printf("HST (13%) %.2f\n", hst);
		
//Display total price

	total_price = hst + purchase_price;
	printf("Total price %.2f\n\n",total_price);
	
// Prompt user for cash_tendered
	printf("Cash tendered ");
        scanf("%f", &cash_tendered);
		
// Display Change in loonies
// Cash tendered - total price / 1
 
	loonies = (cash_tendered - total_price)/ loonies; 
	
	printf("Loonies %d\n",loonies);
	
// Display change in cents
 	

	cents = (cash_tendered- total_price) - loonies;
	
	printf("Cents %.2f\n",cents);
	
	return 0;
}

//END
