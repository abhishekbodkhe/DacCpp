#include <stdio.h>

struct Date
{
    int day;   
    int month; 
    int year;  
};

// Function to initialize a date structure (currently does nothing)
void initDate(struct Date *ptrDate)
{
   
}

// Function to print the date on the console
void printDateOnConsole(struct Date *ptrDate)
{
    printf("Date :  %d/%d/%d \n", ptrDate->day, ptrDate->month, ptrDate->year);
}

// Function to accept date input from the user
void acceptDateFromConsole(struct Date *ptrDate)
{
    
    printf("Enter day : ");
    scanf("%d", &ptrDate->day);
    printf("Enter month : ");
    scanf("%d", &ptrDate->month);
    printf("Enter year : ");
    scanf("%d", &ptrDate->year);
}

// Function to display a menu and get the user's choice
int menu()
{
    int choice;
    
    printf("0. EXIT \n");
    printf("1. Accept Date \n");
    printf("2. Display Date \n");
    printf("Enter your choice - \n");
    
    scanf("%d", &choice);

    return choice;
}

// Main function
int main()
{
    int choice; 
    struct Date d; 

    // Loop until the user chooses to exit
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            // accept date input
            acceptDateFromConsole(&d);
            break;
        case 2:
            //  print the date
            printDateOnConsole(&d);
            break;
        
        default:
            printf("Wrong choice\n");
            break;
        }
    }
    return 0;
}