#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*V 1.1:
Changes:

1) declared i outside of loop, you don't need -std=c99 to compile anymore
2) added a check for existence of historicaldata.csv
*/

/*an instance of this struct holds the weather data for a single day*/
struct DailyData{
    int day;
    int month;
    int year;
    float high;
    float low;
    float precipitation;
    char condition;
};

/*an instance of this struct holds summary information for the weather
for a given month*/
struct MonthlyStatistic{
    float minTemperature;
    float maxTemperature;
    float averageTemperature;
    float totalPrecipitation;
};
int readDailyData(FILE* fp, struct DailyData allData[]);

int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[], int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[],int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw( char c, int num );


int main(void){
    FILE* fp = fopen("historicaldata.csv","r");
    if(!fp){
        printf("you need to put historicaldata.csv into this directory\n");
        exit(0);
    }
    struct DailyData  allData[3000];
    struct DailyData yearData[366];
    int numTotalRecords;

    numTotalRecords = readDailyData(fp, allData);
    int year;
    int reportType;
    int i;
    struct MonthlyStatistic monthly[12];
    printf("Please enter the year for the report: ");
    scanf("%d",&year);
    printf("Please enter the type of report you wish to generate:\n");
    printf("1) summary\n");
    printf("2) detailed\n");
    scanf("%d",&reportType);
    int numDays = getRelevantRecords(year,allData,numTotalRecords,yearData);
    sortYearData(yearData,numDays);

    for(i=0;i<12;i++){
        getStats(i+1,yearData,numDays,&monthly[i]);
    }

    printf("Weather summary for %d\n",year);
    printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
    printf("|-----------|-------|-------|-------|---------|\n");
    for(i=0;i<12;i++){
        printMonthlyStatistic(i+1,&monthly[i]);
    }
    printf("\n\n");
    printf("Precipitation Graph\n");
    for (i=0;i<12;i++){
        graphLine(i+1,&monthly[i]);
	
    }
    if(reportType == 2){
        printf("\n\n");
        printf("Detailed report:");
        printVerbose(yearData,numDays);
    }
	printf("\n");

    return 0;
}

// This functions stores data in the array allData

int readDailyData(FILE* fp, struct DailyData allData[]) {
    
int i=0;
   
    while(fscanf(fp,"%d,%d,%d,%f,%f,%f,%c\n",
        &allData[i].year,&allData[i].month,&allData[i].day,
        &allData[i].high,&allData[i].low,&allData[i].precipitation,
        &allData[i].condition) == 7){
        i++;
    }

    return i;
}
// This function copies over all records from allData to yearData and matches yearWanted

int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]) {

int i = 0;
int j = 0;
int x = 0;
    
	for(i = 0; i < sz; i++)

   	if (allData[i].year == yearWanted) {
	    yearData[x]	= allData[i];
   		x++;
		j++;
	}
    
	return j;
}

// This functions records in the yearData entry

void sortYearData(struct DailyData yearData[], int sz) {

int i, j;   
 	
	for (i = 0; i < sz - 1; i++){
           for (j = 0; j < sz - i - 1; j++) {
            
		if ((yearData[j].month > yearData[j+1].month) || ((yearData[j].month == yearData[j+1].month) && (yearData[j].day > yearData[j+1].day)))
            {
                struct DailyData tmp = yearData[j];
                yearData[j] = yearData[j+1];
                yearData[j+1] = tmp;
            }
        }
    }
}

//This function finds the min, max, average temperature and precipitation

void getStats(int month, const struct DailyData yearData[],int sz,struct MonthlyStatistic* monthly) {

float runningTotal = 0;
float highTemp = 0;
float lowTemp = 200;
float sum=0; 
float precipTotal=0;

int i;

 for (i = 0; i < sz; i++){

    if(month == yearData[i].month){
       
        
	if (highTemp < yearData[i].high){ 

		highTemp = yearData[i].high; 
  	}

	if (lowTemp > yearData[i].low){

		lowTemp = yearData[i].low;
  	}  

	precipTotal+= yearData[i].precipitation;
	sum+=(yearData[i].high+yearData[i].low);

runningTotal++;

	}
}

monthly->averageTemperature = (sum/ runningTotal) /2;
monthly->maxTemperature = highTemp;
monthly->minTemperature = lowTemp;
monthly->totalPrecipitation = precipTotal;

}

// This function will print out a row of summary table

void printMonthlyStatistic(int month,const struct MonthlyStatistic* monthly) {

const char * months[12]= {"January", "February", "March", "April", "May","June", "July", "August", "September", "October", "November", "December"};

printf("| %9s | %-5.1f | %-5.1f | %-5.1f | %-7.1f |\n",months[month-1],
monthly->maxTemperature,
monthly->minTemperature, monthly->averageTemperature,
monthly->totalPrecipitation);
    
}

// This function will print a graphline with percipitation bar graph

void graphLine(int month, const struct MonthlyStatistic* monthly) {

const char * months[12]= {"January", "February", "March", "April", "May","June", "July", "August", "September", "October", "November", "December"};

int total = 0;
int i; 

	
	total = monthly->totalPrecipitation / 10 + 0.6;
             
	printf("\n%10s |%c",months[month-1], monthly->totalPrecipitation);
	        
	for(i = 0; i < total; i++)      
	                                  
		putchar('*');
}

//This function will print out all the data for everyday of the year selected

void printVerbose(const struct DailyData allData[], int sz) {

    static char *months[] = {NULL, "January", "February", "March", "April",
            "May", "June", "July", "August", "September", "October",
            "November", "December"};
int i;
float aver;

    for (i = 0; i < sz; i++) {

        aver = average(allData[i].high,allData[i].low);

        printf("\n%10s %3d %5d: %5.1f  ", months[allData[i].month], allData[i].day, allData[i].year, aver);   

        draw(symbolToDraw(allData[i].condition, aver),20);

    }

	printf("\n");

}

//This function will print out the appropriate symbol for the condition

char symbolToDraw(char condition, float avgTemp) {

    char c = '~';
    char p = ';';
    char s = '@';
    char l = '*';
    
    if(avgTemp < 0 && condition == 'p'){
       condition = '*';

    }else if (condition == 'p'){
        condition = ';';

    }else if( condition == 's'){
        condition = '@';

    }else if( condition == 'c'){
        condition = '~';
    }

return condition;

}

//Calculate the average
float average(float first, float second) {

    float average;
    average = (first + second)/2;
    return average;

}

//Function to print our condition charecetrs

void draw( char c, int num ) {

    int i;//This function is for drying the amount of symbols needed
    for(i=0; i < num; i++){
        printf("%c", c);

        }
}
