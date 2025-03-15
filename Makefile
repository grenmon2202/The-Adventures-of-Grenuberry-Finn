CXX=g++

# Check if clang++ is available, if so use it instead of g++
ifeq ($(shell which clang++ >/dev/null 2>&1; echo $$?), 0)
    CXX=clang++
endif

CXXFLAGS=-std=c++11 -Wall

all: TheAdventuresOfGrenuberryFinn

TheAdventuresOfGrenuberryFinn: main.o Map.o GameUtils.o
	$(CXX) main.o Map.o GameUtils.o -o TheAdventuresOfGrenuberryFinn

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o

Map.o: src/Map.cpp
	$(CXX) $(CXXFLAGS) -c src/Map.cpp -o Map.o

GameUtils.o: src/GameUtils.cpp
	$(CXX) $(CXXFLAGS) -c src/GameUtils.cpp -o GameUtils.o

clean:
	rm -f *.o TheAdventuresOfGrenuberryFinn