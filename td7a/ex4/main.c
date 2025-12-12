#include <assert.h>
#include <stdio.h>
#include <string.h>

int validerEmail(const char *mail) {
  if (mail == NULL) return 0;

  if (strchr(mail, ' ') != NULL) return 0;

  const char *at = strchr(mail, '@');

  if (at == NULL) return 0;
  if (at == mail) return 0;

  const char *dot = strchr(at + 1, '.');

  if (dot == NULL) return 0;
  if (*(dot + 1) == '\0') return 0;

  return 1;
}

int main() {
  // Exemples d'adresses valides
  char *validEmails[] = {"alice@example.com", "alice@10.42.0.1",
                         "alice.123@example.com", "alice-OK@example.com"};

  int nbValid = sizeof(validEmails) / sizeof(validEmails[0]);

  // Exemples d'adresses non valides
  char *invalidEmails[] = {
      "alice.example.com",
      "Abc 123@example.com",
      "@monnomdedomaine.de",
      "alice@example",
  };

  int nbInvalid = sizeof(invalidEmails) / sizeof(invalidEmails[0]);

  // Tester les adresses valides
  printf("Tests des adresses valides:\n");
  for (int i = 0; i < nbValid; i++) {
    char *ptrEmail = validEmails[i];
    printf("%d -- %s\n", i, ptrEmail);
    assert(validerEmail(ptrEmail));
  }
  puts("SUCCÉS");
  // Tester les adresses non valides
  printf("\nAdresses non valides:\n");
  for (int i = 0; i < nbInvalid; i++) {
    char *ptrEmail = invalidEmails[i];
    printf("%d -- %s\n", i, ptrEmail);
    assert(!validerEmail(ptrEmail));
  }
  puts("SUCCÉS");
  puts("\nTous les tests sont passés avec succès.");

  return 0;
}
