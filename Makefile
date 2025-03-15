CXX=g++

# Check if clang++ is available, if so use it instead of g++
ifeq ($(shell which clang++ >/dev/null 2>&1; echo $$?), 0)
    CXX=clang++
endif

CXXFLAGS=-std=c++11 -Wall

all: TheAdventuresOfGrenuberryFinn

TheAdventuresOfGrenuberryFinn: main.o Map.o GameUtils.o GameController.o Player.o
	$(CXX) main.o Map.o GameUtils.o GameController.o Player.o -o TheAdventuresOfGrenuberryFinn

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o

Map.o: src/Map.cpp
	$(CXX) $(CXXFLAGS) -c src/Map.cpp -o Map.o

GameUtils.o: src/GameUtils.cpp
	$(CXX) $(CXXFLAGS) -c src/GameUtils.cpp -o GameUtils.o

GameController.o: src/GameController.cpp
	$(CXX) $(CXXFLAGS) -c src/GameController.cpp -o GameController.o

Player.o: src/Player.cpp
	$(CXX) $(CXXFLAGS) -c src/Player.cpp -o Player.o

clean:
ifeq ($(OS),Windows_NT)
	del /Q *.o TheAdventuresOfGrenuberryFinn.exe
else
	rm -f *.o TheAdventuresOfGrenuberryFinn
endif