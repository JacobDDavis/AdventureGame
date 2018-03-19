/**
 * Room.h - Jacob Davis, March 2018
 *
 * Header file for the Room class. The room plays a vital role in the game as it 
 * determines the players location. Rooms are instantiated and connected to allow
 * transportation between them.
 */

#ifndef ROOM_H
#define ROOM_H

using namespace std;

#include <string>
#include <iostream>
#include <map>

class Room {
private:
    string name;
    string description;
    map<string, Room*> moves;//map containing possible move directions for each room

public:
    Room(string, string);
    Room(string);
    Room();
    string getName();
    string getDescription();
    void printInfo();//prints room name and description
    
    //Connect Function
    void connect(Room *Room, string);//connects rooms together and takes a direction which the room is in
    void printConnected();
    Room* getConnected(string);
    
};

#endif