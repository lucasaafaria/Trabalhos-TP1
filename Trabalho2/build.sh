#!/bin/bash

g++ ../Trabalho1/dominios.h -c ../Trabalho1/dominios.cpp
g++ ../Trabalho1/entidades.h -c ../Trabalho1/entidades.cpp
g++ -c interfaces.h
g++ controladoras.h -c controladoras.cpp
g++ stubs.h -c stubs.cpp
g++ comandos.h -c comandos.cpp
g++ -c main.cpp
g++ -o executar dominios.o entidades.o controladoras.o stubs.o comandos.o main.o 