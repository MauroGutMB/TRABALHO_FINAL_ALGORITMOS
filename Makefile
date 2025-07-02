# Variáveis
CC = gcc
CFLAGS = -Wall -g
EXEC = main
OBJ = main.o src/funcs.o

# Regra padrão
all: $(EXEC)

# Como gerar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Compilar main.c
main.o: main.c src/funcs.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# Compilar funcs.c
src/funcs.o: src/funcs.c src/funcs.h
	$(CC) $(CFLAGS) -c src/funcs.c -o src/funcs.o

# Limpeza
clean:
	rm -f *.o src/*.o $(EXEC)
