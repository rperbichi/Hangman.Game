cmake_minimum_required(VERSION 3.24)
project(HangmanGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(HangmanGame main.cpp Hangman.h Hangman.cpp)
