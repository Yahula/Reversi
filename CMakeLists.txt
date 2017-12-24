cmake_minimum_required(VERSION 3.6.2)
project(Reversi)

set(CMAKE_CXX_STANDATD 98 -Wall -Wextra)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_subdirectory(gtest_src/googletest-master)
include_directories(gtest_src/googletest-master/googletest/include)


set(H_FILES include/Board.h include/Console.h include/Disk.h include/Game.h include/GameRules.h include/HumanPlayer.h include/Player.h include/Reversi_I.h include/AI_Player.h include/Client.h include/RemotePlayer.h)
set(SOURCE_FILES src/Main.cpp src/Board.cpp  src/Console.cpp src/Disk.cpp src/Game.cpp src/GameRules.cpp src/HumanPlayer.cpp src/Player.cpp src/Reversi_I.cpp  src/AI_Player.cpp src/Client.cpp src/RemotePlayer.cpp)
set(TEST_FILES test/GameRules_test.cpp test/AI_test.cpp test/gtestMain.cpp)

add_executable(Reversi ${SOURCE_FILES} ${H_FILES})

add_executable(Reversi_tests test/gtestMain.cpp ${TEST_FILES} ${H_FILES} ${SOURCE_FILES})

#target_link_libraries(Run_tests board)

target_link_libraries(Reversi_tests gtest gtest_main)
