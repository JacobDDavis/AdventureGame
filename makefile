Game: Game.o Room.o
	g++ -g -o Game Game.o Room.o

Game.o: Game.cpp
	g++ -c Game.cpp

Room.o: Room.cpp Room.h
	g++  -c  Room.cpp Room.h


