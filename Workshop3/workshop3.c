

// Workshop 3- Logic
// SIN Validator

#include <stdio.h>

int main (void) {

//SIN DIGITS

int SIN;
int dig9 = SIN % 10;
int dig8 = (SIN/10) % 10;
int dig7 = (SIN/100) % 10;
int dig6 = (SIN/1000) % 10;
int dig5 = (SIN/10000) % 10;
int dig4 = (SIN/100000) % 10;
int dig3 = (SIN/1000000) % 10;
int dig2 = (SIN/10000000) % 10;
int dig1 = (SIN/100000000) % 10;

int alt1 = (dig8*2)+(dig6*2)+(dig4*2)+(dig2*2);
int alt2 = dig7 + dig5 + dig3 + dig1;

int total_alt= alt1 + alt2;

//Title

 printf ("SIN Validator\n");
 printf ("==============\n");

//Prompt user to enter SIN

 printf ("SIN (0 to quit) : \n");
 scanf ("d%", SIN);

while (SIN !=0) {

printf ("Have a nice day!");

}
return 0;

// Check if SIN is valid
 printf ("my alt1 is %d\n", alt1);
 printf ("my alt2 is %d\n", alt2);


// If SIN is valid print ("This is a valid SIN")
// If SIN is invalid print ("This is not a valid SIN.")
// Exit = ("Have a nice day")

}
