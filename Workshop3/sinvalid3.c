#include <stdio.h>

int main(void){

	int sin;
	int sin_2;						
	int check_digit;							
	int odd1 = 0;							
	int even1 = 0;	
	int even2 = 0;							
	int total;								
	int rounded;							
	int temp1;
	int temp2;


	printf("\nSIN Validator");
	printf("\n=============");
		
	do{									
	
		printf("\nSIN (0 to quit): ");
		scanf("%d",&sin);					
		temp2=sin;
		
		if(sin==0)
			printf("\nHave a Nice Day!\n\n");		
		else
		{
			check_digit = sin % 10;				
			sin/=10;

			while(sin != 0){					
				temp1 = sin % 10;
				even1 = temp1*2;
				
				while(even1!=0){			
					even2+=(even1%10);	
					even1/=10;
				}
			
				sin/=10;
			
				temp1 = sin % 10;				
				odd1+=temp1;
				sin/=10;
			}
			total = odd1 + even2;			
		
			rounded=((total+9)/10)*10;
		
			if(rounded-total==check_digit)			
				printf("\nThis is a valid SIN\n");
			else
				printf("\nThis is not a valid SIN\n");
		}

	}while(temp2!=0);						

	return 0;
}
