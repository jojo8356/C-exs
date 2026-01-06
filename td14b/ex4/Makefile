CC = gcc
CFLAGS = -Wall -Werror -std=c23

# Liste des fichiers sources
LIBDIR = ../../lib
LIB = $(wildcard $(LIBDIR)/*.c)
SRC = main.c $(LIB)

# fichiers objets
OBJ = $(SRC:.c=.o)

# Nom de l'exécutable
EXEC = mon_programme

all: $(EXEC) run

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)

run: $(EXEC)
	@./$(EXEC)

.PHONY: all clean