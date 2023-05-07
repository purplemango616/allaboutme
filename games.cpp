/*Your Name Header Here*/
/* Name: Stephanie La Rosa
Date: 2/27/2023
Assignment: Homework 5
Due Date: 3/7/2023
About this project: presents the user with a menu, on which includes three games, shows statistics and resets statistics
Assumptions: it is going to be a long program with tiny difficulties

All work below was performed by Stephanie La Rosa */

/*Headers/Libraries*/
#include <iostream> 
#include <ctime>
#include <iomanip>

using namespace std;

/*Function Declarations*/
void printRules();
void menu();
int getValidMenu(); // making sure number is valid
bool guessNumber();
bool highLow();
bool collectPairs();
void viewStats(int wins, int losses);

int main()
{
    // seeding the random number generator for games
    srand(time(0));
    
    // declaration of games variable for switch statement
    int games, wins = 0, losses = 0;
    bool gameResult;
    
    // calling menu function to show the user the menu of games
    menu();
    // making sure menu choice is true
    games = getValidMenu();
    
    while (games != 0)
    {
        // calling the functions
        switch (games)
        {
            case 1:
                gameResult = guessNumber();
                
                // counts the wins and losses
                if (gameResult == true)
                    wins++;
                else
                    losses++;
                break;
            case 2:
                gameResult = highLow();
                
                // counts the wins and losses
                if (gameResult == true)
                    wins++;
                else
                    losses++;

                break;
            case 3:
                gameResult = collectPairs();
                
                // counts the wins and losses
                if (gameResult == true)
                    wins++;
                else
                    losses++;

                break;
            case 4:
                viewStats(wins, losses);
                break;
            case 5:
                // resets the statistics 
                wins = 0;
                losses = 0;
                cout << "Statistics Reset!" << endl;
                break;
            case 6: 
                printRules();
                break;
        }
        cout << endl;
        menu();
        games = getValidMenu();
    }
    // show stats after quit games
    viewStats(wins, losses);
    cout << "\nThanks for playing!" << endl;
    
    return 0;
}

/*Function definition for COLLECTPAIRS
this function is invoked whenever the user wants to play Collect Pairs.
this function returns true/false depending on if the user wins the game or not*/
bool collectPairs()
{
    int pairs = 0, die1, die2;
    bool pair1Found = false, pair2Found = false, pair3Found = false,
        pair4Found = false, pair5Found = false, pair6Found = false; 
        
    // game welcome message output
    cout << "\nRolling a pair of dice 100 times for pairs!" << endl;
    
    // loop for rolling dice 100 times
    for (int attempt = 1; attempt < 100; attempt++)
    {
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        
        if (die1 == 1 && die2 == 1 && pair1Found == false)
        {
            cout << "PAIR OF ONES found" << endl;
            pair1Found = true;
        }
        else if (die1 == 2 && die2 == 2 && pair2Found == false)
        {
            cout << "PAIR OF TWOS found" << endl;
            pair2Found = true;
        }
        else if (die1 == 3 && die2 == 3 && pair3Found == false) 
        {
            cout << "PAIR OF THREES found" << endl;
            pair3Found = true;
        }
        else if (die1 == 4 && die2 == 4 && pair4Found == false)
        {
            cout << "PAIR OF FOURS found" << endl;
            pair4Found = true;
        }
        else if (die1 == 5 && die2 == 5 && pair5Found == false)
        {
            cout << "PAIR OF FIVES found" << endl;
            pair5Found = true;
        }
        else if (die1 == 6 && die2 == 6 && pair6Found == false)
        {
            cout << "PAIR OF SIXES found" << endl;
            pair6Found = true;
        }
    }
    
    // output if user won or lost
    if (pair1Found == true && pair2Found == true && pair3Found == true && pair4Found == true &&
        pair5Found == true && pair6Found == true)
    {
        cout << "\nYou WIN!" << endl;
        return true; 
    }
    else
        cout << "\nSorry, you lose." << endl;
        return false;

        
}
/*Function definition for GUESSNUMBER
this function is invoked whenever the user wants to play Guess Number.
this function returns true/false depending on if the user wins the game or not*/
bool guessNumber()
{
    // declaring variable for guess number game
    int r, userGuess;
    // r becomes a random number from 1-100
    r = rand() % 100 + 1;
    
    cout << endl;
    cout << "Guess the Number, 1 --> 100! " << endl;
    
    // for loop so the user only has 6 tries to guess the number
    for (int attempt = 1; attempt < 7; attempt++)
    {
        cout << "Attempt " << attempt << "/6 : ";
        cin >> userGuess;
        
        if(userGuess < r)
            cout << "TOO SMALL." << endl;
        if (userGuess > r)
            cout << "TOO BIG." << endl;
        
        if (r == userGuess)
         {
            cout << "You WIN!" << endl;
            return true;
        }
    }
    
    // output if user loses, if user made it out of loop, they lose
    cout << "Sorry, you lose. The number was " << r << endl;
    return false;
}
/*Function definition for HIGHLOW
this function is invoked whenever the user wants to play high low.
this function returns true/false depending on if the user wins the game or not*/
bool highLow()
{
    // intro ouput for high or low game
    cout << "High or Low! Stay alive for 5 rounds to win! (Numbers range from 1 to 1,000)" << endl;
    
    // declaration and initatizing variables for high or low game
    int r, nextR;
    char HorL;
    r = rand() % 1000 + 1;
    
    // for loop with 5 attempts for game
    for(int attempt = 1; attempt < 5; attempt++)
    {
        nextR = rand() % 1000 + 1;
        
        cout << "Round " << attempt << " of 5. The number is " << r << endl;
        cout << "        ... is the next number [H]igher or [L]ower?: ";
        cin >> HorL;
        
        // input validation
        while (HorL != 'H' && HorL != 'L')
        {
            cout << "Enter H or L: ";
            cin >> HorL;
        }
        
        if (HorL == 'H' && nextR > r)
        {
            cout << "The next number is: " << nextR << endl;
            cout << "Correct!" << endl;
        }
        else if (HorL == 'L' && nextR < r)
        {
            cout << "The next number is: " << nextR << endl;
            cout << "Correct!" << endl;
        }
        else
        {
            cout << "The next number is: " << nextR << endl;
            cout << "Sorry, you lose." << endl;
            return false;
        }
        r = nextR;   
    }
    
    // if user made it out of loop, they win because they stayed alive for 5 rounds
    cout << "You WIN!" << endl;
    return true;
}
/*Function definition for VIEWSTATS
this function takes in the number of wins, and losses that the user had while playing their games
this function then prints the win and loss stats neatly to the screen, and returns no value*/
void viewStats(int wins, int losses)
{
    // accounts to prevent error if denominator from being 0
    double percent;
    if (wins == 0 && losses == 0)
        percent = 0;
    else
        percent = (wins/static_cast<double>(wins + losses)) * 100; // calculates percent win
    
    // output of the statistics and calculates win percent
    cout << fixed << showpoint << setprecision(1);
    cout << "STATISTICS:" << endl;
    cout << "-------------------------" << endl;
    cout << "Wins: " << wins << "         Losses: " << losses << endl;
    cout << "Total Win Percent: " << percent << "%" << endl;

}
/*Function definition for MENU 
this function should print the menu for the user and ask/obtain their menu choice.
this function will return the user's menu choice after verifying it's a valid choice on the menu.*/
void menu()
{
    cout<< "GAME MENU:" << endl;
    cout << "--------------------------" << endl;
    cout << "1: PLAY Guess the Number" << endl;
    cout << "2: PLAY High Low" << endl;
    cout << "3: PLAY Collect Pairs" << endl;
    cout << "4: VIEW Statistics" << endl;
    cout << "5: RESET Statistics" << endl;
    cout << "6: RULES" << endl;
    cout << "0: QUIT" << endl;
    cout << "--------------------------" << endl;
}
/*Function definition for GETVALIDMENU 
this function should verify user's menu choice is a valid choice on the menu.*/
int getValidMenu()
{
    // declaring the user's menu choice variable
    int choice;
    // reading in the user's menu choice
    cin >> choice;
    cout << endl;
    
    // input validation while loop 
    while (choice < 0 || choice > 6)
    {
        cout << "Enter an item on the Menu: ";
        cin >> choice;
    }
    return choice;
}
/*Function definition for PRINTRULES
this function prints the rules of all of the games available to the user in this program
that is all this function is responsible for. DO NOT CHANGE this function.*/
void printRules()
{
    cout << "\nRULES:\n\nGuess the Number Game:\nYou'll only get 6 tries to guess a number between 1 and 100!";
    cout << "\nGuess Wisely!\n\nHigh/Low Game:\nMake it through 5 rounds of guessing whether the next random number\n";
    cout << "between 1 and 1,000 is higher or lower than the previous, and you win!\n\n";
    cout << "Collect the Pairs Game:\nRoll two dice 100 times. If in the 100 times you roll a pair\n";
    cout << "of each type (1's, 2's, 3's, 4's, 5's, 6's) at least once, then YOU WIN!\n\n";
    return;
}
