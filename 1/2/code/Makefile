# MIT 6.s096
# Assignment 1 Problem 2 & 3
# Hao Zhang
# 2016.09.24
# Makefile

MAIN = main
TEST = test
MAIN_OBJ = main.o Matrix.o
TEST_OBJ = test.o Matrix.o
CXX = g++
CXXFLAGS = -O0 -std=c++11 -Wall -Wextra -Weffc++ -Werror -pedantic

main: CXXFLAGS += -D NDEBUG
main: $(MAIN_OBJ)
	$(CXX) -o $(MAIN) $(MAIN_OBJ)

test: CXXFLAGS += -D NDEBUG
test: $(TEST_OBJ)
	$(CXX) -o $(TEST) $(TEST_OBJ)

main.o: Matrix.h
test.o: Matrix.h
Matrix.o: Matrix.h

.PHONY = clean
clean:
	-rm $(MAIN) $(TEST) $(MAIN_OBJ) $(TEST_OBJ)
