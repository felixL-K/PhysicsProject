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

MainClass.o: MainClass.hpp CelestialBody.hpp Vector2D.hpp MainClass.cpp CelestialBody.cpp Vector2D.cpp
	$(CC) $(CFLAGS) -c MainClass.cpp CelestialBody.hpp Vector2D.hpp

Vector2D.o: Vector2D.hpp Vector2D.cpp
	$(CC) $(CFLAGS) -c Vector2D.cpp

CelestialBody.o: CelestialBody.hpp Vector2D.hpp MainClass.cpp CelestialBody.cpp Vector2D.hpp MainClass.cpp
	$(CC) $(CFLAGS) -c CelestialBody.cpp MainClass.hpp Vector2D.hpp

SolarSystem.o: SolarSystem.hpp CelestialBody.hpp Vector2D.hpp SolarSystem.cpp CelestialBody.cpp Vector2D.cpp
	$(CC) $(CFLAGS) -c SolarSystem.cpp CelestialBody.hpp Vector2D.hpp

clean :
	rm *.o
	rm *.gch
	rm *.bak
	rm MainClass