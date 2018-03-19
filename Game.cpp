/**
 * Game.cpp - Jacob Davis, March 2018
 * Defines the starting point of the text-based adventure game. 
 * Program begins by initializing rooms and introducing the action string.
 * The program then begins the game loop.
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Room.h"
using namespace std;

int main()
{   
    //initialize rooms
    Room *fort = new Room("Fort", "You are in the fort.");
    Room *canopy = new Room("Canopy", "You are in the canopy.");
    Room *cave = new Room("Cave", "You are in the cave.");
    Room *woods = new Room("Woods", "You are in the woods.");
    Room *tunnel = new Room("Tunnel", "You are in the tunnel.");
    Room *dungeon = new Room("Family Room", "You are in the Dungeon.");
    Room *forest = new Room("Forest", "You are in the Forest.");
    
    //connect rooms together
    canopy->connect(fort, "South");
    canopy->connect(dungeon, "West");

    cave->connect(fort, "West");
    cave->connect(forest, "East");

    dungeon->connect(canopy, "East");
    dungeon->connect(tunnel, "South");

    forest->connect(cave, "West");

    fort->connect(canopy, "North");
    fort->connect(cave, "East");
    fort->connect(woods, "South");
    fort->connect(tunnel, "West");

    tunnel->connect(dungeon, "North");
    tunnel->connect(fort, "East");

    woods->connect(fort, "North");

    Room *currentRoom = fort;//sets the game's starting location
    
    string action;

    //Game loop runs until the game is finished
    /*-------------Begin game-------------*/    
    
    cout << "Welcome to the game. Type 'quit' to end the game at any time.\n";
    while (action != "quit")
    {
        currentRoom->printInfo();
        cout << endl;
        currentRoom->printConnected();

        cout << "Next move? ";
        cin >> action;

        Room* isPossible = currentRoom->getConnected(action);//isPossible created to test if the direction from input is valid
        
        while (action != "quit" && isPossible == NULL)
        {
            cout << "Invalid input" << endl;
            cout << "Next move? ";
            cin >> action;
            isPossible = currentRoom->getConnected(action);
        }
        if (action == "quit")
            break;
        cout << "You move " << action << "." << endl;
        currentRoom->getConnected(action);

        currentRoom = currentRoom->getConnected(action);
    }
    cout << "Game Over.\n";
    return 0; //Exit the program
}
