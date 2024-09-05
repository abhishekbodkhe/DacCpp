#include <stdio.h>


struct Date
{
    int day;   
    int month; 
    int year;  
};

// Function to initialize a date structure 
void initDate(struct Date *ptrDate)
{
    
}

// Function to print the date on the console
void printDateOnConsole(struct Date *ptrDate)
{
    // Date format : day/month/year
    printf("Date :  %d/%d/%d \n", ptrDate->day, ptrDate->month, ptrDate->year);
}

int main(){
    
    return 0;
}
