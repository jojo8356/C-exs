#include "lib/taches.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printUsage(const char *prog) {
  printf("Usage:\n");
  printf("  %s add \"tâche\"   - Ajouter une tâche\n", prog);
  printf("  %s list          - Lister les tâches en cours\n", prog);
  printf("  %s do <num>      - Marquer une tâche comme terminée\n", prog);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printUsage(argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "add") == 0) {
    if (argc < 3) {
      fprintf(stderr, "Erreur: tâche manquante\n");
      printUsage(argv[0]);
      return 1;
    }
    addTask(argv[2]);
  } else if (strcmp(argv[1], "list") == 0) {
    listTasks();
  } else if (strcmp(argv[1], "do") == 0) {
    if (argc < 3) {
      fprintf(stderr, "Erreur: numéro de tâche manquant\n");
      printUsage(argv[0]);
      return 1;
    }
    int taskNum = atoi(argv[2]);
    doTask(taskNum);
  } else {
    fprintf(stderr, "Commande invalide\n");
    printUsage(argv[0]);
    return 1;
  }

  return 0;
}
