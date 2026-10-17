CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = rental

OBJS = main.o fileio.o graph.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp client.h fileio.hpp graph.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

fileio.o: fileio.cpp fileio.hpp client.h
	$(CXX) $(CXXFLAGS) -c fileio.cpp

graph.o: graph.cpp graph.hpp client.h
	$(CXX) $(CXXFLAGS) -c graph.cpp

clean:
	rm -f $(OBJS) $(TARGET)