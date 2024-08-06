CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = ThreadSafeCache

all: $(TARGET)

$(TARGET): main.o Cache.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o Cache.o

main.o: main.cpp Cache.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Cache.o: Cache.cpp Cache.h
	$(CXX) $(CXXFLAGS) -c Cache.cpp

clean:
	rm -f $(TARGET) *.o
