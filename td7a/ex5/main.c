#include <ctype.h>
#include <stdio.h>

void codageCesar(char *message, int cle) {
  for (int i = 0; message[i] != '\0'; i++) {
    char c = message[i];

    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      c = (c - base + cle + 26) % 26 + base;
    }

    message[i] = c;
  }
}

int main() {
  char message[] = "En C je suis au TOP:)";
  int cle = 10;

  printf("Message à envoyer:      %s\n", message);

  codageCesar(message, cle);
  printf("Message crypté   (+%d): %s\n", cle, message);

  codageCesar(message, -cle);
  printf("Message décrypté (-%d): %s\n", cle, message);

  printf("Codage et décodage fonctionnels :)\n");

  return 0;
}
