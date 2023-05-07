/* Name: Stephanie La Rosa
Date: 1-31-2023
Assignment: Homework 2 - Exercise 1: Dividing Fractions
Due Date: 2-6-2023
About this project: Dividing Fractions
Assumptions: Program will be easy to create except the if loop for error

All work below was performed by Stephanie La Rosa */


#include <iostream>
using namespace std;

int main()
{
      // initializing and declaration of numerator and denominators
      int firstNumerator, firstDenominator, secondNumerator, secondDenominator;
      
      //initializing and declaration for dividing the fractions
      int numeratorResult, denominatorResult;
      
      // user input
      cout << "Enter the numerator of the first fraction: ";
      cin >> firstNumerator;
      
      cout << "Enter the denominator of the first fraction: ";
      cin >> firstDenominator;
      
      cout << "Enter the numerator of the second fraction: ";
      cin >> secondNumerator;
      
      cout << "Enter the denominator of the second fraction: ";
      cin >> secondDenominator;
      
      // if user enters 0 print error and abort the program 
      if (firstDenominator == 0 || secondDenominator == 0)
      {
          cout << "You cannot divide by 0! Aborting program" << endl;
      }
      else
      {
    
      // dividing fractions calculation
      numeratorResult = (firstNumerator * secondDenominator);
      denominatorResult = (firstDenominator * secondNumerator);
          
          // output
         cout << firstNumerator << "/" << firstDenominator << " divided by " << secondNumerator << "/" 
         << secondDenominator << " = " << numeratorResult << "/" << denominatorResult << endl;
      }
      

      
     
      
     return 0;
}





