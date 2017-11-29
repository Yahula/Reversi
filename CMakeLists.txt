cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDATD 98 -Wall -Wextra)
#set(CMAKE_CCX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread -Wextra")

include_directories(gtest_src)



set(SOURCE_FILES src/Main.cpp src/Board.cpp include/Board.h src/Console.cpp include/Console.h src/Disk.cpp include/Disk.h src/Game.cpp include/Game.h src/GameRules.cpp include/GameRules.h src/HumanPlayer.cpp include/HumanPlayer.h src/Player.cpp include/Player.h src/Reversi_I.cpp include/Reversi_I.h include/AI_Player.h src/AI_Player.cpp)

set(TEST_FILES test/test_Board.cpp)




add_executable(Reversi ${SOURCE_FILES})

#add_executable(Run_tests test/gtest_main.cpp ${TEST_FILES})

#target_link_libraries(Run_tests gtest_src gtest_main)
#target_link_libraries(Run_tests board)

