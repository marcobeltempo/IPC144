// Workshop 5
// Fraction Simplifier
// Marco Beltempo
// Thursday, November 5, 2015


#include <stdio.h>

int num, num1, denom, denom1;

void simplify(int *numerator, int *denominator);

    int main () {

    //Title

   	 printf("Fraction Simplifier\n");
   	 printf("===================\n");

    //Prompt User for Numerator and Denominator
   
	printf("Numerator: ");
    		scanf("%d", &num);
 			num1 = num;  
	printf("Denominator: ");
   		 scanf("%d", &denom);
			denom1 = denom;
   
    //Call Simplify Function

    simplify(&num1, &denom1);

    //Display Simplified Fraction

    	printf("%d / %d = %d / %d\n", num, denom, num1, denom1);

    return 0;

    }

//Simplify function
   
 void simplify(int *numerator, int *denominator)

// Algorithm to Calculate the lcd and divide it the the numerator and denominator

{
int max;
int lcd;

    
if (*numerator > *denominator)
	max = *denominator;
else
	max = *numerator;

for (lcd = max; lcd >=1; lcd--) {
	if (*numerator % lcd == 0 && *denominator % lcd ==0) {

	*numerator = *numerator / lcd;
	*denominator = *denominator / lcd; 
}

}

}
