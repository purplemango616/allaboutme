/* Name: Stephanie La Rosa
Date: 4-2-2023
Assignment: Homework #7 - String Manipulator 
Due Date: 4-10-2023
About this project: user inputs a string and program must evualuate it based on menu options
Assumptions: this assignment will be easier than the homework #6

All work below was performed by Stephanie La Rosa */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int vowel(string &sentence);
int digit(string &sentence);
string uppercase(string &sentence);
string lowercase(string &sentence);
string currentstring(string &sentence);
string anotherstring (string &sentence);
void menu();
void exit();

int main()
{
    char command;
    string sentence;
    
    // welcome ouput message
    cout << "Input a line of text, up to 100 characters: " << endl;
    getline(cin, sentence); // reads all the way until user clicks enter
    cout << endl;
    
    // output of menu after user inputs string
    menu();
        
    do{
        cout << "\nEnter your menu selection: ";
        cin >> command;
        
        if(command == 'A' || command == 'a')
        {
            vowel(sentence);
        }
        else if(command == 'B' || command == 'b')
        {
            digit(sentence);
        }
        else if(command == 'C' || command == 'c') // works
        {
            uppercase(sentence);
        }
        else if(command == 'D' || command == 'd') // works
        {
            lowercase(sentence);
        }
        else if(command == 'E' || command == 'e') // works
        {
            currentstring(sentence);
        }
        else if(command == 'F' || command == 'f') // works
        {
            anotherstring(sentence);
        }
        else if(command == 'M' || command == 'm') // works
        {
            menu();
        }
        else if(command == 'X' || command == 'x') // works
        {
            exit();
        }
        
    }while(command != 'X' && command != 'x');
    
    
     return 0;
}
// Function Definitions
int vowel(string &sentence)
{
    // declaring and initializing the counter of digits at 0
    int count = 0;
    
    // loop to check for digits
    for (int i = 0; i < sentence.size(); i++)
    {
        sentence[i] = tolower(sentence[i]);
        
        if(sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u')
            count++;
    }
        
    cout << "Number of vowels: " << count << endl;
    
    return count;
}
int digit(string &sentence)
{
    // declaring and initializing the counter of digits at 0
    int count = 0;
    
    // loop to check for digits
    for (int i = 0; i < sentence.size(); i++)
    {
        if(isdigit(sentence[i]))
            count++;
    }
        
    cout << "Number of digits: " << count << endl;

    return count;
}
string uppercase(string &sentence)
{
    // loop to change the rest to uppercase
    for (int i = 0; i < sentence.size(); i++)
    {
        if(isalpha(sentence[i]))
            sentence[i] = toupper(sentence[i]);
    }

    return sentence;
}
string lowercase(string &sentence)
{
    // loop to change the rest to lowercase
    for (int i = 0; i < sentence.size(); i++)
    {
        if(isalpha(sentence[i]))
            sentence[i] = tolower(sentence[i]);
    }

    return sentence;
}
string currentstring(string &sentence)
{
    cout << "\nThe string: " << endl;
    cout << sentence << endl;
    return sentence;
}
string anotherstring(string &sentence)
{
    cout << "Input a new line of text, up to 100 characters: " << endl;
    cin.ignore(); // discard newline character
    getline(cin, sentence); // reads all the way until user clicks enter
    
    return sentence;
}
void menu()
{
    cout << "A)  Display the # of vowels in the string" << endl;
    cout << "B)  Display the # of digits in the string" << endl;
    cout << "C)  Transform the string to uppercase" << endl;
    cout << "D)  Transform the string to lowercase" << endl;
    cout << "E)  Show the current string" << endl;
    cout << "F)  Enter another string" << endl;

    cout << "\nM)  Display this menu" << endl;
    cout << "X)  Exit the program" << endl;
}
void exit()
{
    // goodbye output message
    cout << "Goodbye" << endl;
    // exiting program
    exit(0);
}