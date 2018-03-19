/**
 * Room.cpp - Jacob Davis, March 2018
 *
 * The constructors and methods of the Room class are in this file.
 * 
 *
 */

#include <iostream>
#include <string>

#include "Room.h"

//Constructors
Room::Room(string n, string d)
{
    name = n;
    description = d;
}

Room::Room(string n)
{
    name = n;
}
//return methods
string Room::getName()
{
    return name;
}

string Room::getDescription()
{
    return description;
}

//Print Room Information
void Room::printInfo()
{
    cout << getName() << endl;
    cout << getDescription() << endl;
}

// Functions for connecting rooms
void Room::connect(Room *Room, string direction)
{
    moves[direction] = Room;
}

// Return possible movement directions
Room* Room::getConnected(string direction)
{
    map<string, Room*>::iterator it;
    it = moves.find(direction);
    if(it != moves.end())
        return it->second;
    else
        return NULL;
}

//Prints possible moves
void Room::printConnected()
{
    map<string, Room*>::iterator it;
    cout << endl;
    for(it = moves.begin(); it != moves.end(); ++it)
        cout << it->first << ": " << it->second->getName() << endl;
    cout << endl;
}