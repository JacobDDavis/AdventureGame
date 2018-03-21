CFLAGS=-Wall -W -O0 -fprofile-arcs -ftest-coverage

all: advgame

advgame:
	g++ $(CFLAGS) -o Game Game.cpp Room.cpp

test: advgame
	./Game

clean:
	rm -rf *.o *.gcno *.gcda *.gcov advgame idir
