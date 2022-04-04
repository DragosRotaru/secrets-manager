CC := gcc
SRC := src
OBJ := bin

SOURCES := $(wildcard $(SRC)/**/*.c) $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%%/%.c, $(OBJ)/%%/%.o, $(SOURCES))

all: $(OBJECTS)
	$(CC) $^ -o bin/vault-server

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -I $(SRC) -c $< -o $@