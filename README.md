# Design of TicTacToe

TicTacToe is a popular game. Here I describe how TicTacToewrite a computer 
program that can play it. This is only the model part; the GUI or any other UI
is a separate task

Every slot is either empty or filled with a circle (first player) or cross (second player)

This project contains the source code for building an application that plays the game interactively.
Admittedly the user interface can be improved. The  slots in the game are labelled as follows
	
	0|1|2
	-----
	3|4|5
	-----
	6|7|8

The first play is 'o' and the second player is 'x'. The human player has to input one label as shown above.

The game is built by using a C++ compiler. If using gcc the following command will create an executable named 'ttt'.

	g++ -o ttt game.cpp play.cpp

	
'game_test.cpp' uses the Catch2 unit testing framework for some basic tests.


