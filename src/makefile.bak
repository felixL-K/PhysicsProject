
SUBDIRS = ./GUI ./PhysicLib ./Main

all: truc

cmake:
	(mkdir -p ./PhysicLib/build; cd ./PhysicLib/build; cmake ..; sudo make install)
	(mkdir -p ./GUI/build; cd ./GUI/build; cmake ..; sudo make install)
	(mkdir -p ./Main/build; cd ./Main/build; cmake ..; make)

cleanCmake:
	sudo rm -rf ./PhysicLib/build/*
	sudo rm -rf ./Main/build/*
	sudo rm -rf ./Test/build/*
	sudo rm -rf ./GUI/build/*

truc:
	(cd ./PhysicLib/build; sudo make install)
	(cd ./GUI/build; sudo make install)
	(cd ./Main/build; make)

clean:
	(cd ./PhysicLib/build; make clean)
	(cd ./GUI/build; make clean)
	(cd ./Main/build; make clean)
