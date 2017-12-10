cmake_minimum_required(VERSION 3.8)
project(Reversi)

#set(CMAKE_CXX_STANDATD 98 -Wall -Wextra)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

#add_subdirectory(gtest_src/googletest-release-1.8.0)
#include_directories(gtest_src/googletest-release-1.8.0/googletest/include)
#include_directories(gtest_src/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/Main.cpp src/Board.cpp include/Board.h src/Console.cpp include/Console.h src/Disk.cpp include/Disk.h src/Game.cpp include/Game.h src/GameRules.cpp include/GameRules.h src/HumanPlayer.cpp include/HumanPlayer.h src/Player.cpp include/Player.h src/Reversi_I.cpp include/Reversi_I.h include/AI_Player.h src/AI_Player.cpp include/Client.h src/Client.cpp)

#set(TEST_FILES test/GameRules_test.cpp)




add_executable(Reversi ${SOURCE_FILES})

#add_executable(Reversi_tests test/gtest_main.cpp ${TEST_FILES})

#target_link_libraries(Reversi_tests gtest gtest_main)
#target_link_libraries(Run_tests board)

