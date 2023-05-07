/* Name: Stephanie La Rosa
Date: 1-22-2023
Assignment: Assignment #1 - Hogwarts Express Trolley Menu
Due Date: 1-26-2023
About this project: writing trolley candy menu and calculating final price with wizard tax
Assumptions: I assume I am actually on the train to Hogwarts and I will actually get candy from the trolley 

All work below was performed by Stephanie La Rosa */


#include <iostream>
#include <iomanip>
using namespace std;

int
main ()
{
  // declaration and initialization for trolly menu
  const double beans = 4.00;
  const double frog = 1.50;
  const double bonbons = 2.50;
  const double cake = 6.25;
  
  // declaration and initialization for user input
  int wantBeans, wantFrog, wantBonbons, wantCakes;

  //declaration and initialization for wizard tax and total
  const double wizardTax = 0.065;
  double wizardTaxCalculation;
  double totalBeforeTax;
  double totalWithTax;

  // welcome message
  cout << "Anything off of the trolley, dears?" << endl;
  cout << endl;

  // trolley menu
  cout << fixed << showpoint << setprecision (2);
  cout << "\tTROLLEY MENU" << endl;
  cout << "\t----------------------" << endl;
  cout << "\tBertie Bott's Every Flavour Beans: $" << beans << endl;
  cout << "\tChocolate Frog: $" << frog << endl;
  cout << "\tExploding Bonbons: $" << bonbons << endl;
  cout << "\tCauldron Cakes: $" << cake << endl;
  cout << "\t----------------------" << endl;
  cout << endl;

  // user input
  cout << "How many Bertie Bott's Every Flavour Beans? --> ";
  cin >> wantBeans;

  cout << "How many Chocolate Frogs? --> ";
  cin >> wantFrog;

  cout << "How many Exploding Bonbons? --> ";
  cin >> wantBonbons;

  cout << "How many Cauldron Cakes? --> ";
  cin >> wantCakes;
  
  cout << endl;

  // calculations
  totalBeforeTax = (wantBeans * beans) + (wantFrog * frog) + (wantBonbons * bonbons) +
    (wantCakes * cake);

  wizardTaxCalculation = totalBeforeTax * wizardTax;

  totalWithTax = totalBeforeTax + wizardTaxCalculation;

  // output
  cout << fixed << showpoint << setprecision (2);
  cout << "Total (Before Wizard Tax): $" << totalBeforeTax << endl;
  cout << "Tax (6.50%): $" << wizardTaxCalculation << endl;
  cout << "Total (After Wizard Tax): $" << totalWithTax << endl;
  cout << endl;
  cout << "Enjoy your candies!" << endl;
  cout << endl;
  
  // syllabus bonut points
  cout << "BUBBLE BOWL" << endl;


  return 0;
}


