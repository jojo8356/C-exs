#ifndef TACHES_H
#define TACHES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TODO_FILE "todo.txt"
#define MAX_LINE 256

// Ajoute une tache au fichier todo.txt
void addTask(const char *task);

// Liste les taches en cours (non terminées) avec leur numéro
void listTasks(void);

// Marque une tache comme terminée par son numéro de ligne
void doTask(int taskNum);

// Fonction utilitaire pour obtenir la date du jour au format YYYYMMDD
char *getDate(void);

#endif // TACHES_H
