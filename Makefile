#example name
NAME=expr
#compiler name
CC=clang++
#flags
CFLAGS=-g -std=c++11 -Wall -Wextra -Wpedantic -Wno-write-strings# -I Header/
SRC= $(wildcard src/*.cpp)
OBJ= $(SRC:.cpp=.o)


all: $(OBJ)
	$(CC) $(CFLAGS) -o main $^

clean:
	rm -f *~ src/*.o

%.o: %.cpp
$(CC) -o $@ -c $< $(CFLAGS)
