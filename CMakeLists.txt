cmake_minimum_required(VERSION 3.6.2)
project(Reversi)

#set(CMAKE_CXX_STANDATD 98 -Wall -Wextra)
set(CMAKE_CXX_FLAGS -pthread)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_subdirectory(gtest_src/googletest-master)
include_directories(gtest_src/googletest-master/googletest/include)


set(H_FILES src/Client/include/Board.h src/Client/include/Console.h src/Client/include/Disk.h src/Client/include/Game.h src/Client/include/GameRules.h src/Client/include/HumanPlayer.h src/Client/include/Player.h src/Client/include/Reversi_I.h src/Client/include/AI_Player.h src/Client/include/Client.h src/Client/include/RemotePlayer.h)
set(SOURCE_FILES src/Client/Main.cpp src/Client/Board.cpp src/Client/Console.cpp src/Client/Disk.cpp src/Client/Game.cpp src/Client/GameRules.cpp src/Client/HumanPlayer.cpp src/Client/Player.cpp src/Client/Reversi_I.cpp src/Client/AI_Player.cpp src/Client/Client.cpp src/Client/RemotePlayer.cpp)
set(TEST_FILES test/GameRules_test.cpp test/AI_test.cpp test/gtestMain.cpp)

add_executable(Reversi ${SOURCE_FILES} ${H_FILES})

add_executable(Reversi_tests test/gtestMain.cpp ${TEST_FILES} ${H_FILES} ${SOURCE_FILES})

#target_link_libraries(Run_tests board)

target_link_libraries(Reversi_tests gtest gtest_main)
