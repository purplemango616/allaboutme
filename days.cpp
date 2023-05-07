/* Name: Stephanie La Rosa
Date: 2-1-2023
Assignment: Assignment 2 - Exercise 2: Days in a Month
Due Date: 2-6-2023
About this project: allowing the user to get the days of a month
Assumptions: it will be hard to program febraray 

All work below was performed by Stephanie La Rosa */


#include <iostream>
using namespace std;

int main()
{
    
    // initialize variables
    int month, year, days;
    
    // user input
    cout << "Enter a month (1-12): ";
    cin >> month;

    cout << "Enter a year: ";
    cin >> year;

    // making sure user entered correct month
    if (month >= 1 && month <= 12)  
    {
        if (month == 2)  // we need to check leap year
        {
           
               // check if divisible by 100, 
               if (year % 100 == 0) 
               {
                       // if the year is also divisible by 400 --> leap
                        if (year % 400 == 0)
                        {
                            days = 29;
                        }
                       // if the year is not divisible by 400 --> not leap
                         else
                         {
                             days = 28;
                         }
               }
               else //but what if not? check if divisible by 4
               {
                        // if the year is divisible by 4 --> leap
                         if (year % 4 == 0)
                         {
                             days = 29;
                         }
                        //if the year if not divisible by 4 --> not leap
                         else
                         {
                              days = 28;
                         }
               }
        }      
        else
        {
            //output days of regular month
            switch (month)
            {
                case 1:
                case 3: 
                case 5: 
                case 7:
                case 8: 
                case 10:
                case 12: 
                    days = 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    days = 30;
                    break;
            }
        }     // output
            cout << "\nNumber of days: " << days << endl;
    }
    else
    {
        // for incorrect month user input
        cout << "\nInvalid Month Entered. Aborting Program." << endl;
    }
    

    
    
    return 0;    
}





