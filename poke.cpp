/* Name: Stephanie La Rosa
Date: 4-11-2023
Assignment: FINAL HW ASSIGNMENT
Due Date: 4-28-2023
About this project: (write a small blurb about what this project's goals are/what tasks it accomplishes)
Assumptions: assumes correct user input the pokemon go game will work good

All work below was performed by Stephanie La Rosa */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include <ctime>
using namespace std;

struct Pokemon
{
    int pokeNumber;
    string name;
    string type;
    string region;
    int catchPercent;
    string dexEntry;
    int numberCaught;
    int numberSeen;
};

// function declarations
void trainer (string &trainerName);
void getUserRegion (string &regionchoice);
void hunt (Pokemon * dex, int size, string regionchoice, string command, int &pokeballs, int &greatballs, int &ultraballs, int &numberCaught, int &numberSeen);
void pokemonlist (Pokemon * dex, int size, string &trainerName, int numberCaught);
void statistics (int &numberCaught, int &numberSeen);
void inventory (int &pokeballs, int &greatballs, int &ultraballs);
void dexInfo (Pokemon * dex, int size, string &name, string type, string dexEntry);
void reset (Pokemon * dex, int size, int &numberCaught, int &numberSeen);
void menu ();
void exitprogram (Pokemon * dex, int size, string &trainerName, int numberCaught);

int main()
{
    Pokemon * dex;
    /*"dex" will act as the name of your Pokemon array that will be created later on. 
    You can change this name if you wish.*/
    int size;
    string trainerName, regionchoice, command;
    int numberCaught = 0, numberSeen = 0;
    string name, type, dexEntry;
    
    // seeding the random number generator for games
    srand(time(0));

    ifstream poke;
    poke.open("poke.txt"); // opens the poke.txt file
    
    // checking if file opens
    // if it does then the program continues, if not program exits
    if (!poke)
    {
        cout << "POKE.TXT FILE FAILED TO OPEN, ENDING PROGRAM." << endl;
        exit(0);
    }
    
    // reading in size from file
    poke >> size;
    poke.ignore(); // ignoring newline after file size

    // created a dynamic array 
    dex = new Pokemon[size];
    
    // copying contents of poke.txt 
    for (int i = 0; i < size; i++)
    {
        poke >> dex[i].pokeNumber;
        poke.ignore();
        
        getline(poke, dex[i].name, ',');
        
        getline(poke, dex[i].type, ',');
        
        getline(poke, dex[i].region, ',');
        
        poke >> dex[i].catchPercent;
    
        poke.ignore();
        getline(poke, dex[i].dexEntry);
        
        dex[i].numberCaught = 0;
            
        dex[i].numberSeen = 0;
    }
    
    poke.close(); // closes poke.txt
    
    trainer(trainerName); // asking for user's name to find pokemons
    
    // tracking the number of each type of Pokeball the user has 
    int pokeballs = 10;
    int greatballs = 10; 
    int ultraballs = 10;
    
    getUserRegion(regionchoice); // asks trainer for what region they have to visit
    menu(); // shows menu after welcoming the trainer
    
    do
    {
        cout << "\nSelection > ";
        cin >> command;
        cin.ignore();
        
        // accepts any capitalization variation for menu option
        for(int i = 0; i < command.length(); i++)
        {
            command[i] = toupper(command[i]);
        }
        
        // trainer using menu choices
        if (command == "HUNT") 
        {
            hunt(dex, size, regionchoice, command, pokeballs, greatballs, ultraballs, numberCaught, numberSeen);
        }
        else if (command == "POKEMON") 
        {
            pokemonlist(dex, size, trainerName, numberCaught); 
        }
        else if (command == "STATISTICS") 
        {
            statistics(numberCaught, numberSeen);
        }
        else if (command == "INVENTORY")
        {
            inventory(pokeballs, greatballs, ultraballs);
        }
        else if (command == "DEX")
        {
            dexInfo(dex, size, name, type, dexEntry);
        }
        else if (command == "RESET")
        {
            reset(dex, size, numberCaught, numberSeen);
        }
        else if (command == "MENU")
        {
            menu();
        }
        else if (command == "EXIT")
        {
            exitprogram(dex, size, trainerName, numberCaught);
        }
        
    }while(command != "EXIT" && (pokeballs+greatballs+ultraballs > 0));
    
    delete[]dex; // cleanup of the dynamic array
    
    return 0;
}
// function definitions
void trainer(string &trainerName)
{
    // welcoming the trainer output message
    cout << "What's your name, trainer? ";
    getline(cin, trainerName);
    
    cout << "\nWelcome, " << trainerName << ", to the Programming I Safari Zone!" << endl;
    cout << "You'll have 30 chances to catch Pokemon, make them count!" << endl;
    cout << "The hunt will end when you choose or when you run out of Pokeballs." << endl;
}
void getUserRegion(string &regionchoice)
{
    // ask trainer what region they would like to travel to
    cout << "\nWhich region would you like to visit?" << endl;
    cout << "Enter Kanto, Johto, Hoenn, or Sinnoh" << endl;
    getline(cin, regionchoice);
        
    // input to accept any capitalization variation for region
    for(int i = 0; i < regionchoice.length(); i++)
        regionchoice[i] = toupper(regionchoice[i]);
        
    // user input validation
    while(regionchoice != "KANTO" && regionchoice != "JOHTO" && regionchoice != "HOENN" && regionchoice != "SINNOH")
    {
        cout << "Which region would you like to visit?" << endl;
        cout << "Enter Kanto, Johto, Hoenn, or Sinnoh" << endl;
        getline(cin, regionchoice);

        
        // converting the input to all uppercase
        for(int i = 0; i < regionchoice.length(); i++)
            regionchoice[i] = toupper(regionchoice[i]);
    } 
    cout << "\nTravelling to " << regionchoice << endl;
}
void hunt(Pokemon * dex, int size, string regionchoice, string command, int &pokeballs, int &greatballs, int &ultraballs, int &numberCaught, int &numberSeen)
{
    // counter for how many there is in each region
    int kantoCounter = 0, johtoCounter = 0, hoennCounter= 0, sinnohCounter = 0;
    
    int random; // random pokemon 
    
    bool validball; // loop variable for user input validation ball choice
    
    int ballchoice; // starting number of balls
    
    int pokeCatchRate = 0, greatCatchRate = 20, ultraCatchRate = 40; // each ball catch rate
    
    int pokeChance, greatChance, ultraChance; // variables chance based on pokemon catch percent
    
    int randNum; // random number generator for catch ball chance
    
    // counting how many pokemons in each region
    for(int i = 0; i < size; i++)
    {
        if(dex[i].region == "Kanto")
            kantoCounter++;
        else if(dex[i].region == "Johto")
            johtoCounter++;
        else if (dex[i].region == "Hoenn")
            hoennCounter++;
        else 
            sinnohCounter++;
    }
        
    // pokemon has spawned output
    if(regionchoice == "KANTO")
    {
        random = rand() % kantoCounter + 1;
    }
    else if (regionchoice == "JOHTO")
    {
        random = rand() % johtoCounter + kantoCounter + 1;
    }
    else if (regionchoice == "HOENN")
    {
        random = rand() % hoennCounter + johtoCounter + kantoCounter + 1;
    }
    else if(regionchoice == "SINNOH")
    {
        random = rand() % sinnohCounter + hoennCounter + johtoCounter + kantoCounter + 1;
    }
        
    cout << "\nA wild " << dex[random-1].name << " just appeared!" << endl;

    // if pokemon is baby, no balls used
    if (dex[random-1].catchPercent == 0)
    {
        cout << "\n Oh! That's a baby Pokemon! We'll take them to the daycare." << endl;
        numberSeen++;
        numberCaught++;
        dex[random-1].numberSeen++;
        dex[random-1].numberCaught++;
        validball = false; 
        return;
    }
        
    // output of which ball they want to use/how many they have left
    cout << "\nChoose a ball to throw: " << endl;
    cout << "1 - Poke Ball \t (You have: " << pokeballs << ")" << endl;
    cout << "2 - Great Ball \t (You have: " << greatballs << ")" << endl;
    cout << "3 - Ultra Ball \t (You have: " << ultraballs << ")" << endl;
    cout << "Choose Ball > ";
   
    do
    {
        validball = false;
        cin >> ballchoice;
        cin.ignore();

        if (ballchoice == 1 || ballchoice == 2 || ballchoice == 3)
        {
            if (ballchoice == 1 && pokeballs > 0)
            {
                validball = true;
            }
            else if (ballchoice == 2 && greatballs > 0)
            {
                validball = true;
            }
            else if (ballchoice == 3 && ultraballs > 0)
            {
                validball = true;
            }
            else
            {
                cout << "You have none of them!" << endl;
                cout << "Choose Ball > ";
            }
        }
        else
        {
            cout << "Invalid Selection. Try again." << endl;
            cout << "Choose Ball > ";
        }
    }while(!validball);
    
    // random number calculation for ball chance of catching pokemon
    randNum = rand() % 100 + 1;
    
    if (ballchoice == 1) 
    {
        cout << "Threw a Poke Ball!" << endl;
        for (int i = 0; i < size; i++)
        {
            pokeChance = (pokeCatchRate + dex[random-1].catchPercent); 
        }
        
        if (randNum <= pokeChance) 
        {
            cout << "Congratulations! You caught " << dex[random-1].name << "!" << endl;
            numberCaught++; // increases counter
            numberSeen++; // increases counter
            dex[random-1].numberCaught++; // counts for struct
            dex[random-1].numberSeen++; // counts for the struct
        }
        else
        {
            cout << dex[random-1].name << " ran away. :-(" << endl;
            numberSeen++; // increases counter
            dex[random-1].numberSeen++; // counts for the struct
        }
        // reduce number of pokeballs
        pokeballs--;
    }
    else if (ballchoice == 2)
    {
        cout << "Threw a Great Ball!" << endl;
        for (int i = 0; i < size; i++)
        {
            greatChance = greatCatchRate + dex[random-1].catchPercent;
        }
        
        if (randNum <= greatChance)
        {
            cout << "Congratulations! You caught " << dex[random-1].name << "!" << endl;
            numberCaught++; // increases counter
            numberSeen++; // increases counter
            dex[random-1].numberCaught++; // counts for struct
            dex[random-1].numberSeen++; // counts for the struct
        }
        else
        {
            cout << dex[random-1].name << " ran away. :-(" << endl;
            numberSeen++; // increases counter
            dex[random-1].numberSeen++; // counts for the struct
        }
        // reduce number of greatballs each time its used
        greatballs--;
    }
    else if (ballchoice == 3)
    {
        validball = true;
        cout << "Threw an Ultra Ball!" << endl;
        for (int i = 0; i < size; i++)
        {
            ultraChance = ultraCatchRate + dex[random-1].catchPercent;
        }
        
        if (randNum <= ultraChance)
        {
            cout << "Congratulations! You caught " << dex[random-1].name << "!" << endl;
            numberCaught++; // increases counter
            numberSeen++; // increases counter
            dex[random-1].numberCaught++; // counts for struct
            dex[random-1].numberSeen++; // counts for the struct
        }
        else
        {
            cout << dex[random-1].name << " ran away. :-(" << endl;
            numberSeen++; // increases counter
            dex[random-1].numberSeen++; // counts for the struct
        }
        // reduce number of ultraballs
        ultraballs--;
    }
    return;
}
void pokemonlist(Pokemon * dex, int size, string &trainerName, int numberCaught)
{
    // outputs if trainer has not caught any pokemons
    if (numberCaught == 0)
    {
          cout << "You haven't caught any pokemons yet!" << endl;
          return;
    }
    
    // iterates through the Pokemon array and print out information for each caught Pokemon
    cout << trainerName << "'s POKEMON:" << endl;
    for (int i = 0; i < size; i++)
    {
        if (dex[i].numberCaught >= 1)
        {
            cout << "no " << dex[i].pokeNumber << "\t" << dex[i].name <<endl;
        }
    }
}
void statistics(int &numberCaught, int &numberSeen)
{
    // accounts to prevent error if denominator from being 0
    double percent;
    if (numberSeen == 0)
        percent = 0;
    else
        percent = numberCaught/static_cast<double>(numberSeen) * 100; // calculates percent win
    
    // output of the statistics and calculates win percent
    cout << fixed << showpoint << setprecision(2);
    cout << "Total Pokemon Caught: " << numberCaught << endl;
    cout << "Total Pokemon Seen: " << numberSeen << endl;
    cout << "Overall Catch Rate: " << percent << "%" << endl;
}
void inventory (int &pokeballs, int &greatballs, int &ultraballs)
{
    cout << "\nYou have:" << endl;
    cout << pokeballs << " PokeBalls" << endl;
    cout << greatballs << " Great Balls" << endl;
    cout << ultraballs << " Ultra Balls" << endl;
}
void dexInfo (Pokemon * dex, int size, string &name, string type, string dexEntry)
{
    string search, temp; // variable to look through the array 
    cin >> search;
    
    // transforms search (pokemon name) to all upper before looking for it
    for (int a = 0; a < search.length(); a++)
    {
        search[a] = toupper(search[a]);
    }

    bool match = false;
    for (int i = 0; i < size; i++)
    {
        temp = dex[i].name;
        
        // transforms temp to all upper
        for (int p = 0; p < temp.length(); p++)
        {
            temp[p] = toupper(temp[p]);
        }

        if (temp == search)
        {
            match = true;
            cout << "Name: " << dex[i].name << endl;
            cout << "Type: " << dex[i].type << endl;
            cout << "Dex: " << dex[i].dexEntry << endl;
            return;
        }
    }
    
    if (!match) // output if pokemon is not found in array
    {
        cout << "No Pokedex entry for " << search << endl;
    }
}  
void reset (Pokemon * dex, int size, int &numberCaught, int &numberSeen)
{
    // resets pokemons caught and seen
    numberCaught = 0;
    numberSeen = 0;
    for (int i = 0; i < size; i++)
    {
        dex[i].numberCaught = 0;
        dex[i].numberSeen = 0;
    }
    statistics(numberCaught, numberSeen);
    return;
}
void menu()
{
    cout << "\nHUNT \t\t(Go hunting for Pokemon!)" << endl;
    cout << "POKEMON \t(See the Pokemon you've caught.)" << endl;
    cout << "STATISTICS \t(See your catch statistics.)" << endl;
    cout << "INVENTORY \t(See your current inventory.)" << endl;
    cout << "DEX NAME \t(ex: DEX BULBASAUR would view Bulbasaur's Pokedex entry." << endl;
    cout << "RESET \t\t(Reset your Pokemon catches.)" << endl;
    cout << "MENU \t\t(Reprint this menu.)" << endl;
    cout << "EXIT" << endl;
}
void exitprogram(Pokemon * dex, int size, string &trainerName, int numberCaught)
{
    cout << endl;
    pokemonlist (dex, size, trainerName, numberCaught);
    exit(0);
}