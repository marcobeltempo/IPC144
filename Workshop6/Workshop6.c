// Marco Beltempo
// Workshop 6- Dice Throws
// This program prompts user for a number between 1 - 12 
// Program runs until both dice equal total sought

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int diceRolls(int diceTotal1);

int main(void){

int totalSought;
//Title
printf("Game of Dice\n");
printf("============\n");

do     {

	printf("Enter total sought : ");
 		scanf("%d", &totalSought);
// User must enter number between 2-12
 	if(totalSought >= 13 || totalSought <= 0 || isalpha(totalSought)){
 	
	printf("** Invalid Input! Try Again! **\n");

 	}

} 	while(totalSought >= 13 || totalSought <= 0 || isalpha(totalSought));
// Call the random dice roll function
	diceRolls(totalSought);
return 0;

}

//This function rolls two random number until it equals the numer sought
int diceRolls(int diceTotal1){

int i;
srand(time(NULL)+1);
int x = 0;
int y = 0;

for (i = 1; (x + y) != diceTotal1; i++){
 x = ((rand()) % 6)+1; //Dice 1
 y = ((rand()) % 6)+1; // Dice 2
 printf("Result of throw %d : %d + %d\n", i,x,y); //Result of dice 1 & 2

}

	i = i-1; // account for off by 1 error
	printf("You got your total in %d throws!\n",i);

}


