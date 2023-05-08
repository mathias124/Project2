cmake_minimum_required(VERSION 3.24)
project(Project2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Project2 main.c card.h list.c list.h gameboard.c gameboard.h validateFile.h SW.h readFile.h Links.h Prints.h)
