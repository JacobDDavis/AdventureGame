# AdventureGame
A C++ text-based adventure game

The text-based adventure game is an opportunity to display understanding of coding practices and implementations. Based on a college project, I revamped and improved upon my existing files. A simple but functional model of a text-based adventure.

## Getting Started
Simply navigate to the directory and use the provided makefile. This will produce a file called "Game" which is the executable used to run the game.

You begin in the fort and are able to navigate through the rooms via directions provided by each room.

### QA
Included with the game is an automated defect checker written in Python 3 by the name of "defectChecker.py."
This uses Pexpect to run the game and test moving into every room as well as attempt to move out of bounds before quitting. At the end, it verifies that it received the expected output with every move.

Additionally the makefile makes use of the gcov coverage analysis tool. After running the program, an analysis can be produced using:

```
gcov Room.cpp
```

And

```
gcov Game.cpp
```

This generates the gcov files Room.cpp.gcov and Game.cpp.gcov respectively which contain exact counts of the number of times each statement in the code is executed.


## Authors
*Jacob Davis
