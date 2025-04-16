CXX = g++ // C++ compiler
CXXFLAGS = -std=c++17 -Wall -g // compiler flags

OBJS = main.o calculator.o // object files
TARGET = calculator // final binary

$(TARGET): $(OBJS) // link target
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp calculator.hpp // main dependency
	$(CXX) $(CXXFLAGS) -c main.cpp

calculator.o: calculator.cpp calculator.hpp // calculator dependency
	$(CXX) $(CXXFLAGS) -c calculator.cpp

clean: // cleanup rule
	rm -f *.o $(TARGET)
