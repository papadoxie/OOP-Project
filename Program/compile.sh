#!/bin/bash

g++ ./source/main.cpp \
-Wall -lSDL2 -fdiagnostics-color=always \
-o ./bin/VirusSimulator \
./source/City.cpp \
./source/Clean.cpp \
./source/FileHandler.cpp \
./source/Human.cpp \
./source/HumanList.cpp \
./source/Infected.cpp \
./source/Randomizer.cpp \
./source/Screen.cpp \
./source/Time.cpp