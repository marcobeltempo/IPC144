#include <stdio.h>

int future (int prin, int year, int rate)

{
	int i; 
	int result;
	
	
	result = 1;
	for  (i = 0; i < year; i++) 
		result = prin * rate;
	
	return result;
	

}


int main (void)

{

	float total, princ;
	float annual_rate;
	int years;
	

	printf("Investment Calculator\n");
	printf("=====================\n");
	
	printf("Principal  :  ");
	scanf("%f", &princ);

	printf("Annual Rate: ");
	scanf("%f", &annual_rate);

	printf("No of years:");
	scanf("%f", &years); 

	total = future;
 

	printf("%f^%f=%d\n",annual_rate, years, total);
	
return 0;
}


