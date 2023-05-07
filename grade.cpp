/* Name: Stephanie La Rosa
Date: 2-2-2023
Assignment: Assignment #2 - Exercise 3: COP3014 Grade Calculator
Due Date: 2-6-2023
About this project: calculate user's overall course grade at the end of the class
Assumptions: this will be a long complicated program

All work below was performed by Stephanie La Rosa */


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
      // declaration and initialization for variables
      const int ASSIGNPTSPOSS = 700;
      const int MIDTERMPTSPOSS = 100;
      const int REVELPOTSPOSS = 591;
      const int FINALPTSPOSS = 100;
      
      int assignptsmade, midtermptsmade, revelptsmade, finalptsmade, extracredit; 
      double finalgradeaverage;
            
      char extracreditmade, finalgrade;
            
      // variables for math calculations for each grade points catergory
      long double A, B, C, D;
      
      // user input
      cout << "Assignment Points Made: ";
      cin >> assignptsmade;
      
      cout << "Midterm Score: ";
      cin >> midtermptsmade;
      
      cout << "Revel Points Made: ";
      cin >> revelptsmade;
      
      cout << "Score on the Final Assignment: ";
      cin >> finalptsmade;
      
      cout << "Did you earn extra credit? (y/n): ";
      cin >> extracreditmade;
     
      // loop to see if user inputed y/n for extra credit
      //this allows the program to go through the correct process if user got extra credit or not
      if (extracreditmade == 'Y' || extracreditmade == 'y' || extracreditmade == 'N' || extracreditmade == 'n')
      {
                  if (extracreditmade == 'Y' || extracreditmade == 'y')
                  {
                      cout << "Extra Credit Points Earned: ";
                      cin >> extracredit;
                  }
                  else 
                  {
                      //if user inputs "n" the extra credit for the calculation will be 0
                      extracredit = 0;
                  }
                  
                  cout << fixed << showpoint << setprecision (1);
                  A = (static_cast<double>(assignptsmade+extracredit)/ASSIGNPTSPOSS) * 0.5;
            
                  B = (static_cast<double>(midtermptsmade)/MIDTERMPTSPOSS) * 0.25;
                  
                  C = (static_cast<double>(revelptsmade)/REVELPOTSPOSS) * 0.1;
            
                  D = (static_cast<double>(finalptsmade)/FINALPTSPOSS) * 0.15;
                 
                  
                  finalgradeaverage = (A + B + C + D) * 100.0;
                  
                  if (finalgradeaverage >= 90.00 && finalgradeaverage <= 100.00)
                  {
                      finalgrade = 'A';
                  }
                  else if (finalgradeaverage >= 80.00 && finalgradeaverage <= 89.99)
                  {
                      finalgrade = 'B';
                  }
                  else if (finalgradeaverage >= 69.00 && finalgradeaverage <= 79.99)
                  {
                      finalgrade = 'C';
                  }
                  else if (finalgradeaverage >= 60.00 && finalgradeaverage <= 68.99)
                  {
                      finalgrade = 'D';
                  }
                  else if (finalgradeaverage >= 0.00 && finalgradeaverage <= 59.99)
                  {
                      finalgrade = 'F';
                  }
                  
                  // output
                  cout << "\nFinal Course Average: " << finalgradeaverage << "%" << endl;
                  cout << "Final Course Letter Grade: " << finalgrade << endl;
      } 
      else 
      {
          cout << "\nInvalid option, exiting program" << endl;
      }
      
     
      
     return 0;
}



