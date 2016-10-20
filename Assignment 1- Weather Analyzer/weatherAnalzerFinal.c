// Marco Beltempo
// Assignment 1- Version 1.0
// IPC-144SLL
// Student ID: 03128095
// Started: 10/9/2015 
// Compltete: 10/16/2015
// Due Date: 10/16/2015

# include <stdio.h>
# define SYM 20

float averageTemp (float low, float high); 

int  main (void) {

	char condition;		 //Declaring variables
	int days, counter;	//store days entered
	float sum = 0, high_temp, low_temp, avg; 	//sum and avg will be used to calculate overall 
	
		printf("Weather Analyzer\n"); 	//Title
		printf("=============\n");

do	

{		
	printf("Please enter a positive number of days: ");  //Force the user to enter anything greater than zero
		scanf("%d", &days);

} 	while (days <= 0);


for	
	(counter = 1; counter <=days; counter ++)	//The user will be prompted depening on the # of days entered

	{
		printf("\nEnter today's high: ");	//Enter high temp
			scanf("%f",&high_temp);
			
		printf("Enter today's low: ");		//Enter low temp
			scanf("%f",&low_temp);
			
		printf("Enter today's conditions (s: sunny, c: cloudy, p: precipitation): "); //Enter the condition
			scanf(" %c", &condition);
	 
		float result;
			
		result = averageTemp (high_temp, low_temp);	//Call the averageTemp function to calculate average
			
		printf("Today's average temperature is: %0.2f \n", result);	//Display average for that day
		
		int sym_count = 0;

		while 	(condition == 's' && sym_count < SYM) {	//user enters"s" it displays @
				sym_count+=1;	
					printf("@"); 		
		 	}

		while	(condition == 'c' && sym_count < SYM) {	//user enters "c" it displays ~ 
			
				sym_count+=1;	
					printf("~");		 
				}

		 while  ((condition == 'p' && result <= 0 && sym_count < SYM)) {
	     	
				sym_count+=1;	
				 	 printf("*");	// user enters p and average is <= 0 display *
				}

		while ((condition == 'p' && result > 0 && sym_count < SYM)) {
								
				sym_count+=1;	
					printf(";");	// user enters p and the average is >0 displays ;
		}
		
		sum += (high_temp+low_temp)/2;	// daily average is calculated and stored in sum
		
}
		avg = sum /days;	//The overall average is calulated and printed to the screen

			printf("\naverage for all %d days is: %0.2f degrees \n", days, avg);	



}			

float averageTemp(float high,float low)	//function that calculates the daily average

{

	float result;
	
	result = (high + low) / 2;
	
	return result;
}

			
		
