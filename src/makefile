
SUBDIRS = ./GUI ./PhysicLib ./Main

all: truc

truc:
	(mkdir -p ./PhysicLib/build; cd ./PhysicLib/build; cmake ..; sudo make install)
	(mkdir -p ./GUI/build; cd ./GUI/build; cmake ..; sudo make install)
	(mkdir -p ./Main/build; cd ./Main/build; cmake ..; make)


clean:
	sudo rm -rf ./PhysicLib/build/*
	sudo rm -rf ./Main/build/*
	sudo rm -rf ./Test/build/*
	sudo rm -rf ./GUI/build/*
