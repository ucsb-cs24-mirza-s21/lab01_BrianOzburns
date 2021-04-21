car: car.cpp, doors.hpp, car.cpp, perf.cpp, perf.hpp
	g++ -o car car.cpp perf.cpp -Wall -g --std=c++11

all: car