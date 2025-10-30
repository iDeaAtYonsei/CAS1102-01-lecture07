
CXX      := g++
CXXFLAGS := -std=c++23 -O2 -Wall -Wextra -pedantic
LDFLAGS  :=
TARGET   := main

SRC := main.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 편의 타깃
.PHONY: run clean debug
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
