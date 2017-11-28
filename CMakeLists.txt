cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES src/Main.cpp src/Board.cpp include/Board.h src/Console.cpp include/Console.h src/Disk.cpp include/Disk.h src/Game.cpp include/Game.h src/GameRules.cpp include/GameRules.h src/HumanPlayer.cpp include/HumanPlayer.h src/Player.cpp include/Player.h src/Reversi_I.cpp include/Reversi_I.h)
add_executable(Reversi ${SOURCE_FILES})