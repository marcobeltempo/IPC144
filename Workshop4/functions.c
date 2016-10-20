// Excercise to test functions

# include <stdio.h>

double future_value (double principal, double rate, int periods); 

int main (void)

{

	double princ;
	double rates;
	int years;
	double result;
	
	printf("Investment Calculator\n");
	printf("=====================\n");

	printf("Principal :  ");	
	scanf("%lf",&princ);

	printf("Annual Rate: ");
	scanf("%lf",&rates);
	
	printf("No of Years: ");
	scanf("%d",&years);

	result  = future_value (princ,rates,years);
		
	printf("\nThe future value is $ %.2lf \n",result);

	return 0;

}

double future_value(double principal, double rate, int periods)

{

	int i;	
	double value = 1 + rate;
	double result = 1;

	for (i = 0; i < periods; i++)
	
	{
		result *= value;
	}

	result *= principal;
	return result;

}
