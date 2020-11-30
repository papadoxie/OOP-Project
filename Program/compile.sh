#!/bin/bash

g++ ./source/Simulator/Simulator.cpp \
-Wall -lSDL2 -lncurses -fdiagnostics-color=always \
-o ./bin/VirusSimulator \
./source/Simulator/Simulator_Menu.cpp \
./source/Simulator/Simulator_OnCleanup.cpp \
./source/Simulator/Simulator_OnEvent.cpp \
./source/Simulator/Simulator_OnInit.cpp \
./source/Simulator/Simulator_OnLoop.cpp \
./source/Simulator/Simulator_OnRender.cpp \
./source/Simulation/Simulation.cpp \
./source/Simulation/City.cpp \
./source/Simulation/FileHandler.cpp \
./source/Simulation/Human.cpp \
./source/Simulation/Random.cpp \
./source/Simulation/Time.cpp