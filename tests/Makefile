CC = g++
CFLAGS = -Wall -g

SRC = alltests.cpp
OBJ = $(SRC:.c=.o)
EXE = bin/test

all: $(EXE)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

clean: $(OBJ) $(EXE)
	rm $(OBJ) $(EXE)