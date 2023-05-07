/* Name: Stephanie La Rosa
Date: 3-22-2023
Assignment: Array Practice - Simulating a Queue with Symbols
Due Date: 3/28/2023
About this project: managing a virtual queue with keyboard symbols
Assumptions: this is going to a long program and i might struggle a bit

All work below was performed by Stephanie La Rosa */

#include <iostream>
#include <string>
using namespace std;

//Function Declarations
void help();
void serve(char line[], int &currentLineLength);
void enter(char line[], int &currentLineLength, char symbol);
void cut(char line[], int &currentLineLength, char symbol, char symbol2);
bool findSymbol(char line[], int &currentLineLength, char symbol);
void leave(char line[], int &currentLineLength, char symbol);
void status(char line[], int &currentLineLength, char symbol);
void first(char line[], int &currentLineLength);
void last (char line[], int &currentLineLength);
void exit (char line[], int &currentLineLength);

int main()
{
    // declaring and initializing the max length of the line array
    const int MAXLENGTH = 20;
    char line[MAXLENGTH];

    // setting the counter to 0 for how many symbols are in line
    int currentLineLength = 0;
    
    // declaring the string command for user input
    string command;
    
    // declaring the character command for user input
    char symbol, symbol2;
    
    // welcome message
    cout << "Welcome to the Virtual Line!" << endl;
    
    do 
    {
        // user input
        cin >> command;
            
        if(command == "help") 
        {
            help(); 
        }
        else if (command == "serve") 
        {
            serve(line, currentLineLength);
        }
        else if (command == "enter") 
        {
            cin >> symbol;
            enter(line, currentLineLength, symbol);
        }
        else if (command == "cut") 
        {
            cin >> symbol >> symbol2;
            findSymbol(line, currentLineLength, symbol);
            cut(line, currentLineLength, symbol, symbol2); 
        }
        else if (command == "leave") 
        {
            cin >> symbol;
            leave(line, currentLineLength, symbol);
        }
        else if (command == "status") 
        {
            status(line, currentLineLength, symbol);
        }
        else if (command == "first") 
        {
            first(line, currentLineLength);  
        }
        else if (command == "last") 
        {
            last(line, currentLineLength); 
        }
        else if(command == "exit") 
        {
            exit(line, currentLineLength); 
        }
    }while (command != "exit");
    
    return 0;
}

//Function Definitions
void help() 
{
    // output when user uses help command
    cout << "-----------------COMMANDS-----------------" << endl;
    cout << "serve : serve next customer in the line" << endl;
    cout << "enter $ : $ enters the line in the back" << endl;
    cout << "cut @ $ : @ cuts in to the line in front of $" << endl;
    cout << "leave $ : $ would leave the line" << endl;
    cout << "status : print the status of the line" << endl;
    cout << "first : print the item in the front of the line" << endl;
    cout << "last : print the item in the back of the line" << endl;
    cout << "help : reprint this menu" << endl;
    cout << "exit : see ya!" << endl;
    cout << "------------------------------------------" << endl;
    
    return;
}
void serve(char line[], int &currentLineLength)
{
    // output if line is empty
    if(currentLineLength == 0)
    {
        cout << "The line is empty." << endl;
        return;
    }
    else
    {
        cout << "Serving " << line[0] << endl;
        
        for(int i = 0; i < currentLineLength - 1; i++)
        {
            line[i] = line[i + 1];
        }
        currentLineLength--;
        return;
    }
}
void enter(char line[], int &currentLineLength, char symbol)
{
    const int MAXLENGTH = 20;
    if(currentLineLength == MAXLENGTH)
    {
        cout << "Line full." << endl;
        return;
    }
    if (findSymbol(line, currentLineLength, symbol))
    {
        cout << symbol << " already in line." << endl;
        return;
    }
    
    line[currentLineLength] = symbol;
    currentLineLength++;
}
void cut(char line[], int &currentLineLength, char symbol, char symbol2)
{
    const int MAXLENGTH = 20;
    // checking if line is full
    if(currentLineLength == MAXLENGTH)
    {
        cout << "Line full." << endl;
        return;
    }
    
    // checking if symbol1 is already in the line
    if(findSymbol(line, currentLineLength, symbol) != false)
    {
        cout << symbol << " is already in line." << endl;
        return;
    }
    
    // checking is symbol2 is in line, if not no cutting in line
    if(findSymbol(line, currentLineLength, symbol2) == false)
    {
        cout << "Cannot cut in front of " << symbol2 << endl;
        cout << symbol2 << " not in line." << endl;
        return;
    }
    
    // shifts the symbol2 after symbol 1 spot to the right (cuts in line)
    for(int i = 0; i < currentLineLength; i++)
    {
        // looking for symbol2
        if(line[i] == symbol2)
        {
            for(int k = currentLineLength; k > i; k--)
            {
                line[k] = line[k-1];
            }
            line[i] = symbol; // inserts symbol where symbol2 
            currentLineLength++;
            // ouput 
            cout << symbol << " cut in line in front of " << symbol2 << endl;
            return;
        }
    }
}
bool findSymbol(char line[], int &currentLineLength, char symbol)
{
    // looks to see if symbol is in line
    for (int i = 0; i < currentLineLength; i++)
    {
        if(line[i] == symbol)
            return true;
    }
    return false; // if symbol is not found
}
void leave(char line[], int &currentLineLength, char symbol)
{
    // output if character is not in line 
    if(findSymbol(line, currentLineLength, symbol) == false)
    {
        cout << symbol << " is not in line." << endl;
        return;
    }
    
    // loop for finding the symbol that wants to leave and shifting the line to the left
    for(int i = 0; i < currentLineLength; i++)
    {
        if(line[i] == symbol)
        {
            for(int k = i; k < currentLineLength - 1; k++)
                line[k] = line[k+1];
        }
    }
    currentLineLength--; // decreases the line by 1 - character that left
    // output for showing the symbol that left the line
    cout << symbol << " has left the line." << endl;
}
void status(char line[], int &currentLineLength, char symbol)
{
    // output for when no one is in line
    if(currentLineLength == 0)
    {
        cout << "The line is empty." << endl;
        return;
    }
    else
    {
        // printing the line on screen
        cout << "There are " << currentLineLength << " items in line: ";
        for(int i = 0; i < currentLineLength - 1; i++)
            cout << line[i] << ", ";
        cout << line[currentLineLength-1] << endl;
    }
}
void first(char line[], int &currentLineLength)
{
    // output that there is no one in line
    if(currentLineLength == 0)
    {
        cout << "The line is empty." << endl;
        return;
    }
    else // output for when there is someone first in line
        cout << line[0] << " is first in line." << endl;
}
void last (char line[], int &currentLineLength)
{
    // output that there is no one in line
    if(currentLineLength == 0)
    {
        cout << "The line is empty." << endl;
        return;
    }
    
    // output for character last in line
    cout << line[currentLineLength-1] << " is last in line." << endl;
}
void exit(char line[], int &currentLineLength)
{
    // output for showing what the line looks at, at time of exiting
    cout << "There are " << currentLineLength << " items in line: ";
    // loop to print the line
    for(int i = 0; i < currentLineLength - 1; i++)
        cout << line[i] << ", ";
    cout << line[currentLineLength-1] << endl;
    // exiting program
    exit(0);
}
