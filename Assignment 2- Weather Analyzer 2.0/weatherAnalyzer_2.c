// Assignment 2- Weather Analyzer 2.0
// Marco Beltempo
// Due: 11/20/15

/* This program will prompt the user for a number of days between 1 and 14. Then the user will be prompted to enter the daily high, low, & condition. The 
program will calculate the daily average. Then print a graphical symbol for the conditions. Finally calculate the overall average for all the days. */
#include <stdio.h>

void displayResult( int days , float allDaysAverage);
char symbolToDraw(char condition, float averageTemperature);
void draw ( char c, int num );
float average (float first, float second);
int getInteger(int min, int max);
void getDailyData( float* high, float* low, char * condition);
void clear(void);

int main(void) {

    int numDays;
    int i;
    float sum = 0;
    float dailyHigh;
    float dailyLow;
    char conditions;
    float dailyAvg = 0;
	
    //Title
    printf("Weather Analyzer 2.0\n");
    printf("====================\n");
	
    //Prompt the user for a number of days
    printf("How many days of data?\n");
    
	//get an integer between 1 and 14
	
	numDays = getInteger(1,14);

   for (i = 0; i < numDays; i++){

	getDailyData(&dailyHigh, &dailyLow, &conditions);
    
	dailyAvg = average(dailyHigh, dailyLow);
	printf("Today's average temperature is: %.2f\n", dailyAvg);

	sum += dailyAvg;
	
	draw(symbolToDraw(conditions, dailyAvg), 20);
}

displayResult(numDays, (sum/numDays));	

return 0;

}

//Prompts user for number of days between 1-14.

int getInteger(int min, int max) {

int days;
int keepTrying = 1;
int rc;
char after;
min = 1;
max = 14;

do {
	printf("Enter an integer between 1 and 14: ");
		rc = scanf("%d%c", &days, &after);
		
	if	(rc == 0) {

		printf("ERROR! Try again!");
		clear();

	} else if (after != '\n') { 
		printf("ERROR! Try again!");
		clear();
	
	} else if (days < min || days > max) {
		printf("ERROR! Try again!");
		clear();	
	} else	
		keepTrying = 0;

	} while  (keepTrying == 1);

return days;		
}

// Prompts the user for the high, low, & condition. Seperated by commas.

void getDailyData( float* high, float* low, char * condition) {

char comma1, comma2, after;
int keepTrying = 1;


do {

	printf("Enter today's high, low and condition (c=cloudy, s=sunny, p= precipitation) separated by commas: ");
		 scanf("%f %c %f %c %c", &*high, &comma1, &*low, &comma2, &*condition);
	
	if (*high < *low || *low > *high){
	printf("Error! Try again!\n");
	clear();
		
	}else if (comma1 != ',' || comma2 != ',') {
	printf("Error! Try again!\n");
 	clear();
	
	
	} else if ((*condition != 'c') && (*condition != 's') && (*condition != 'p')) {
	printf("Error! Try again!\n");
	clear();

	} else
		keepTrying = 0;
} while (keepTrying ==1);
}

// Calculates the daily average

float average (float first, float second) {

float result = (first + second) / 2;

return result;

}

// Function to draw a row of charecters

void draw ( char c, int num) {

int i;

for (i = 0; i < num; i++){

printf("%c", c);
}
printf("\n");
}

// Draws a row of symbols depeneding on the condition and average entered

char symbolToDraw(char condition, float averageTemperature){

int sym_count =0;

if (condition == 's'){

		printf("@");
		
}
else if (condition == 'c') {
	
		printf("~");
}

else if (condition == 'p' && averageTemperature <= 0) {
	
		printf("*");
}

else if (condition = 'p' && averageTemperature > 0) {
	
		printf(";");
}

}

//Calculates and displays overall result for days entered

void displayResult( int days , float allDaysAverage){

char a[10][10]={"one","two","three","four","five","six","seven","eight","nine"};

float average;

//average = allDaysAverage/ days;

//If the total days is < 10 it will print the word

if (days < 10){

printf("Your %s day average is %0.2f\n",a[days-1],allDaysAverage);

// If >10 it will print the number

}else
printf("Your %d average is %0.2f\n", days, allDaysAverage);


}

// Clear empties the input buffer 
 
 void clear(void)
 
{
         while (getchar() != '\n')
                 ;  // empty statement intentional 
 }

