/* Name: Stephanie La Rosa
Date: 2-7-2023
Assignment: Assignment 3 - Exercise 1: Pennies
Due Date: 2-15-2023
About this project: program that calculates how much a person would earn over a period of
time if his or her salary is one penny the first day, two pennies the second day, and 
continues to double each day.
Assumptions: having to double for each day will be tricky

All work below was performed by Stephanie La Rosa */


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
      // declared variables
      int days;
      double sum = 0, pennySalary = 0.01;
      
      // user input
      cout << "Please enter the number of days worked: ";
      cin >> days;
      
      // do loop for what the program must do
      do
      {
            // input validation
            if (days < 1)
            {
              cout << "Invalid number of days.  Try again \n";
              cout << "Please enter the number of days worked: ";
              cin >> days;
            }
      } while (days <= 0);
      
      // output
      cout << fixed << showpoint << setprecision (2);
      cout << "\nDay \t" << "\t\tAmount Earned" << endl;
      cout << "-------------------------------------------" << endl;
      
      // for loop for pennies calculation
      for (int i = 1; i <= days; i++)
      {
          cout << i << "\t\t\t$ " << pennySalary << endl;
          sum += pennySalary;
          pennySalary *= 2;
      }
      
      // output 
      cout << "\nTotal earnings: $ " << sum << endl;
      
     return 0;
}



