CC = gcc
CFLAGS = -Wall -Werror -std=c23

# Dossier de la librairie
LIBDIR = ../../lib

# Fichiers objets
OBJS = exABStructBFS.o $(LIBDIR)/arbres.o $(LIBDIR)/filegen.o $(LIBDIR)/pilegen.o

# Cible principale
TARGET = bfsab

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

exABStructBFS.o: exABStructBFS.c $(LIBDIR)/arbres.h
	$(CC) $(CFLAGS) -c exABStructBFS.c -o $@

$(LIBDIR)/arbres.o: $(LIBDIR)/arbres.c $(LIBDIR)/arbres.h $(LIBDIR)/filegen.h $(LIBDIR)/pilegen.h
	$(CC) $(CFLAGS) -c $(LIBDIR)/arbres.c -o $@

$(LIBDIR)/filegen.o: $(LIBDIR)/filegen.c $(LIBDIR)/filegen.h
	$(CC) $(CFLAGS) -c $(LIBDIR)/filegen.c -o $@

$(LIBDIR)/pilegen.o: $(LIBDIR)/pilegen.c $(LIBDIR)/pilegen.h
	$(CC) $(CFLAGS) -c $(LIBDIR)/pilegen.c -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	@echo "\\nLancement de l'exécutable..."
	./$(TARGET)
