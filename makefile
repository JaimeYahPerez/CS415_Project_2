CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = rental

OBJS = main.o fileio.o graph.o toposort.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp client.hpp fileio.hpp graph.hpp toposort.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

fileio.o: fileio.cpp fileio.hpp client.hpp
	$(CXX) $(CXXFLAGS) -c fileio.cpp

graph.o: graph.cpp graph.hpp client.hpp
	$(CXX) $(CXXFLAGS) -c graph.cpp

toposort.o: toposort.cpp toposort.hpp graph.hpp

clean:
	rm -f $(OBJS) $(TARGET)