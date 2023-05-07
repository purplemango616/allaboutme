/* Name: Stephanie La Rosa
Date: 2/20/2023
Assignment: Homework 4 - Calculating NFL Passer Rating
Due Date: 2/24/2023
About this project: display the passer rating for each 
quarterback, and then prints a message detailing who's 
rating was the best, and what the difference between the 
ratings was.
Assumptions: hardest part of program will be the function with special conditions

All work below was performed by Stephanie La Rosa */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// function declaration (prototype) for getPasserRating
double getPasserRating(int passAttempts, int completions, int passYards, int touchdownPass, int interceptions);

int main()
{
    // declaring variables for user input of nfl passer rating calculations
    int passAttempts, completions, passYards, touchdownPass, interceptions;
    double playerA, playerB, difference;
    
    // welcome message for the NFL Quarterback Passer Rating Calc
    cout << "Welcome to the NFL Quarterback Passer Rating Calculator!" << endl;
    
    // user input for player A
    cout << "\nEnter single game information for Player A: " << endl;
        
    cout << "Attempts: ";
    cin >> passAttempts;
        
    cout << "Completions: ";
    cin >> completions;
        
    cout << "Passing Yards: ";
    cin >> passYards;
        
    cout << "Touchdowns: ";
    cin >> touchdownPass;
        
    cout << "Interceptions: ";
    cin >> interceptions;
    
    // calling function getPasserRating for player A
    playerA = getPasserRating(passAttempts, completions, passYards, touchdownPass, interceptions);
    
    // user input for player B
    cout << "\nEnter single game information for Player B: " << endl;
        
    cout << "Attempts: ";
    cin >> passAttempts;
        
    cout << "Completions: ";
    cin >> completions;
        
    cout << "Passing Yards: ";
    cin >> passYards;
        
    cout << "Touchdowns: ";
    cin >> touchdownPass;
        
    cout << "Interceptions: ";
    cin >> interceptions;
    
    // calling function getPasserRating for player B
    playerB = getPasserRating(passAttempts, completions, passYards, touchdownPass, interceptions);
    
    // caluclation for output is player A is better than other and vice versa
    difference = abs(playerA - playerB);
    
    // output 
    cout << fixed << showpoint << setprecision (1);
    cout << "\nPlayer A's single game passer rating: " << playerA << endl;
    cout << "Player B's single game passer rating: " << playerB << endl;
    
    if (playerA > playerB)
        cout << "Player A was better than Player B by a difference of " << difference << endl;
    else if (playerB > playerA)
        cout << "Player B was better than Player A by a difference of " << difference << endl;
    else
        cout << "Player A and B have the same rating!" << endl;
    
    cout << endl;
    
    // seeing if players had perfect passer rating
    if (playerA >= 158.33) // perfect rating if passer rating > 158.33
        cout << "Player A had a PERFECT passer rating." << endl;
    if (playerB >= 158.33) // perfect rating if passer rating > 158.33
        cout << "Player B had a PERFECT passer rating." << endl;
        
    return 0;
}
// function definition for getPasserRating
double getPasserRating(int passAttempts, int completions, int passYards, int touchdownPass, int interceptions)
{
    // declaring variables for math based on user input in main
    double a, b, c, d, passerRating;
    
    // passer rating calculation by parts
    a = ((static_cast<double>(completions)/passAttempts) - 0.3) * 5;
    b = ((static_cast<double>(passYards)/passAttempts) - 3) * 0.25;
    c = (static_cast<double>(touchdownPass)/passAttempts) * 20;
    d = 2.375 - (static_cast<double>(interceptions)/passAttempts) * 25;
    
    // special conditions:
    // if result greater than 2.375 then its 2.375
    if (a > 2.375)
        a = 2.375;
    if (b > 2.375)
        b = 2.375;
    if (c > 2.375)
        c = 2.375;
    if (d > 2.375)
        d = 2.375;
    // if result is negative then its 0
    if (a < 0)
        a = 0;
    if (b < 0)
        b = 0;
    if (c < 0)
        c = 0;
    if (d < 0)
        d = 0;
    if (passAttempts == 0) // making sure that denominator is not 0 in calculations to avoid error
        passerRating = 0;
    else
        // passer rating complete calculation
        passerRating = (((a+b+c+d)/6) * 100);
        
    // return value back to main is the calculation for passer rating
    return passerRating;
}



