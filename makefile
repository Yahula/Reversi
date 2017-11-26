#Yahel Ben Ishay 305016297

a.out: Board.o Console.o Disk.o Main.o Game.o GameRules.o HumanPlayer.o Player.o Reversi_I.o
	g++ Board.o Console.o Disk.o Main.o Game.o GameRules.o HumanPlayer.o Player.o Reversi_I.o

Board.o: Board.cpp Board.h Disk.h
	g++ -c Board.cpp

Console.o: Console.cpp Console.h Board.h
	g++ -c Console.cpp

Disk.o: Disk.cpp Disk.h
	g++ -c Disk.cpp

Game.o: Game.cpp Game.h Console.h Reversi_I.h
	g++ -c Game.cpp

GameRules.o: GameRules.cpp GameRules.h Disk.h Player.h Board.h
	g++ -c GameRules.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h Player.h
	g++ -c HumanPlayer.cpp

Player.o: Player.cpp Player.h Disk.h
	g++ -c Player.cpp

Reversi_I.o: Reversi_I.cpp Reversi_I.h GameRules.h Disk.h
	g++ -c Reversi_I.cpp

Main.o: Main.cpp Game.h
	g++ -c Main.cpp
