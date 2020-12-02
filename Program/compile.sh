#!/bin/bash

g++ main.cpp \
-o ./bin/VirusSimulator \
./source/Simulator/Simulator.cpp \
./source/Simulator/Simulator_Menu.cpp \
./source/Simulator/Simulator_OnCleanup.cpp \
./source/Simulator/Simulator_OnEvent.cpp \
./source/Simulator/Simulator_OnInit.cpp \
./source/Simulator/Simulator_OnLoop.cpp \
./source/Simulator/Simulator_OnRender.cpp \
./source/Simulation/Simulation.cpp \
./source/Simulation/City/City.cpp \
./source/FileHandling/FileHandler.cpp \
./source/Simulation/Human/Human.cpp \
./source/Helpers/Random.cpp \
./source/Helpers/Time.cpp \
-Wall -lSDL2 -lncurses -fdiagnostics-color=always