#compiler name
#CC=clang++
CC=g++
#flags
CFLAGS= -std=c++11 -Wall -Wextra -Wpedantic -Wno-write-strings# -I Header/
SRC= $(wildcard src/*.cpp)
OBJ= $(patsubst src/%.cpp, obj/%.o, $(SRC))


all: $(OBJ)
	$(CC) -O2 $(CFLAGS) -o main $^

#debug: clean all
#    valgrind --leak-check=full --show-leak-kinds=all ./main

clean:
	rm -f obj/*.o

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
