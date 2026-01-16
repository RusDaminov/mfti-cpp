CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = program

$(TARGET): main.cpp test.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp test.cpp

clean:
	rm -f $(TARGET)

.PHONY: clean