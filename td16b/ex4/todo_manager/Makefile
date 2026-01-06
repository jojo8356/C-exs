CC = gcc
CFLAGS = -Wall -Werror -std=c23

TARGET = todo
SRCS = main.c lib/taches.c

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
	rm -f todo.txt

test: $(TARGET)
	# Initialisation du fichier de test
	echo "Tâche 1" > todo.txt
	# Test 1: ajout et listage
	./todo add "Tâche 2"
	./todo add "Tâche 3"
	./todo list > tests/sortie1.txt
	# Vérification des résultats
	diff tests/sortie1.txt tests/1-sortie.txt
	diff todo.txt tests/1-todo.txt
	# Test 2: marquage comme terminée et listage
	./todo do 2
	./todo list > tests/sortie2.txt
	diff tests/sortie2.txt tests/2-sortie.txt
	@echo "Tous les tests passent!"
