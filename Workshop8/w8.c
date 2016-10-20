/*
 * C Program to Count Number of Words in a given Text Or Sentence
 */

char wordCount();

#include <stdio.h>
#include <string.h>

int main (void){

printf("Word Counter\n");
printf("============\n");

wordCount();

} 

char wordCount()

{
        
char str[100];
printf("Text to be anazlyzed : ");
	    scanf("%[^\n]s", str);

    int count = 0, i;
 
    for (i = 0;str[i] != '\0';i++)
    {
        if (str[i] == ' ')
            count++;    
    }
    printf("Word count           : %d\n", count + 1);
}
