#include "taches.h"

char *getDate(void) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char buffer[11]; // Taille suffisante pour "YYYY-MM-DD" + '\0'

  // Formate la date dans le buffer
  strftime(buffer, sizeof(buffer), "%Y%m%d", &tm);

  // copie dynamique pour renvoyer
  return strdup(buffer);
}

void addTask(const char *task) {
  FILE *f = fopen(TODO_FILE, "a");
  if (f == NULL) {
    perror("Erreur ouverture fichier");
    return;
  }
  fprintf(f, "%s\n", task);
  fclose(f);
}

void listTasks(void) {
  FILE *f = fopen(TODO_FILE, "r");
  if (f == NULL) {
    perror("Erreur ouverture fichier");
    return;
  }

  char line[MAX_LINE];
  int num = 1;

  while (fgets(line, MAX_LINE, f) != NULL) {
    // Supprimer le retour à la ligne
    line[strcspn(line, "\n")] = '\0';

    // Afficher uniquement les tâches non terminées (ne commençant pas par 'x ')
    if (line[0] != 'x' || line[1] != ' ') {
      printf("%d: %s\n", num, line);
    }
    num++;
  }

  fclose(f);
}

void doTask(int taskNum) {
  FILE *f = fopen(TODO_FILE, "r");
  if (f == NULL) {
    perror("Erreur ouverture fichier");
    return;
  }

  // Lire toutes les lignes dans un tableau dynamique
  char **lines = NULL;
  int count = 0;
  char line[MAX_LINE];

  while (fgets(line, MAX_LINE, f) != NULL) {
    line[strcspn(line, "\n")] = '\0';
    lines = realloc(lines, (count + 1) * sizeof(char *));
    lines[count] = strdup(line);
    count++;
  }
  fclose(f);

  // Vérifier que le numéro de tâche est valide
  if (taskNum < 1 || taskNum > count) {
    fprintf(stderr, "Numéro de tâche invalide\n");
    for (int i = 0; i < count; i++) {
      free(lines[i]);
    }
    free(lines);
    return;
  }

  // Vérifier que la tâche n'est pas déjà terminée
  if (lines[taskNum - 1][0] == 'x' && lines[taskNum - 1][1] == ' ') {
    fprintf(stderr, "Tâche déjà terminée\n");
    for (int i = 0; i < count; i++) {
      free(lines[i]);
    }
    free(lines);
    return;
  }

  // Marquer la tâche comme terminée
  char *date = getDate();
  char *newLine = malloc(strlen(lines[taskNum - 1]) + strlen(date) + 4);
  sprintf(newLine, "x %s %s", date, lines[taskNum - 1]);
  free(date);
  free(lines[taskNum - 1]);
  lines[taskNum - 1] = newLine;

  // Réécrire le fichier
  f = fopen(TODO_FILE, "w");
  if (f == NULL) {
    perror("Erreur ouverture fichier");
    for (int i = 0; i < count; i++) {
      free(lines[i]);
    }
    free(lines);
    return;
  }

  for (int i = 0; i < count; i++) {
    fprintf(f, "%s\n", lines[i]);
    free(lines[i]);
  }
  free(lines);
  fclose(f);
}
