CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = main.cpp
TARGET = calculator

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
