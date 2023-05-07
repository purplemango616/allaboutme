/* Name: Stephanie La Rosa
Date: 2-8-2023
Assignment: Assignment 3 - Exercise 2: Temperature
Due Date: 2-15-2023
About this project: allows the user to enter temperatures 
in Fahrenheit, and converts their temperature to Celsius
Assumptions: 

All work below was performed by Stephanie La Rosa */


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    
    // declare variables
    double tempC, tempF, tempAverage = 0, tempTotal = 0;
    int tempCounter = 0; 
    char convertTempChoice;
    
    do 
    {
        // user input
        cout << "Temperature to convert from F to C: ";
        cin >> tempF;
        tempCounter++;
        
        // temperature conversion
        tempC = (tempF - 32) * 5.0/9.0;
        
        // total temperature for average
        tempTotal = tempC + tempTotal;
        
        // output
        cout << fixed << showpoint << setprecision (2);
        cout << static_cast<int>(tempF) << "F = " << tempC << "C" << endl;
        
        // asking the user if they want to convert another one 
        cout << "\nEnter another? (Y or N): ";
        cin >> convertTempChoice;
    
        
    } while (convertTempChoice == 'Y' || convertTempChoice == 'y');
    
    // input validation
    if(convertTempChoice != 'Y' && convertTempChoice != 'y' && convertTempChoice != 'N' && convertTempChoice != 'n')
    {
        cout << "Invalid Character Entry... Aborting program." << endl;
    }
    else
    {
        // average temperatures that were Converted
        tempAverage = tempTotal/tempCounter;
    
        // output
        cout << "Number of Temps Converted: " << tempCounter << endl; 
        cout << "Average Temp: " << tempAverage << "C" << endl;
    }
    
    return 0;
}




