# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

MainClass: MainClass.o CelestialBody.o Vector2D.o
	$(CC) $(CFLAGS) -o MainClass MainClass.o CelestialBody.o Vector2D.o

# The MainClass.o target can be written more simply

MainClass.o: MainClass.hpp CelestialBody.hpp Vector2D.hpp
	$(CC) $(CFLAGS) -c MainClass.cpp CelestialBody.hpp Vector2D.hpp

Vector2D.o: Vector2D.hpp
	$(CC) $(CFLAGS) -c Vector2D.cpp

CelestialBody.o: CelestialBody.hpp Vector2D.hpp MainClass.hpp
	$(CC) $(CFLAGS) -c CelestialBody.cpp MainClass.cpp Vector2D.hpp
