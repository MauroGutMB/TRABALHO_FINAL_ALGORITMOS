# Compiler e flags
CC = gcc
CFLAGS = -Wall -g
LIBS = -lncursesw -lsqlite3

# Nome dos executáveis
MAINEXEC = usuario
ADMINEXEC = admin

# Fontes compartilhadas
COMMON_SRC = \
    src/funcs.c \
    UI/ui.c \
    db/dbCONN/dbFetch.c \
    db/dbFUNC/flights.c \
    db/dbFUNC/users.c

# Fontes específicas
MAIN_SRC = usuario.c $(COMMON_SRC)
ADMIN_SRC = admin.c $(COMMON_SRC)

# Objetos
MAIN_OBJ = $(MAIN_SRC:.c=.o)
ADMIN_OBJ = $(ADMIN_SRC:.c=.o)

# Regra padrão: tudo
all: $(MAINEXEC) $(ADMINEXEC)

# Como gerar o executável usuario
$(MAINEXEC): $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) $(LIBS)

# Como gerar o executável admin
$(ADMINEXEC): $(ADMIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $(ADMIN_OBJ) $(LIBS)

# Regra genérica para compilar cada .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(MAINEXEC) $(ADMINEXEC) $(MAIN_OBJ) $(ADMIN_OBJ)
