# Compiler e flags
CC = gcc
CFLAGS = -Wall -g -lncurses -lsqlite3

# Nome do executável
EXEC = main

# Fontes principais
SRC = \
    main.c \
    src/funcs.c \
    UI/ui.c \
    db/dbCONN/dbFetch.c \
    db/dbFUNC/flights.c \
    db/dbFUNC/users.c

# Objetos gerados
OBJ = $(SRC:.c=.o)

# Regra padrão
all: $(EXEC)

# Como gerar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Regra genérica para compilar cada .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(EXEC) $(OBJ)
