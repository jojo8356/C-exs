#include <stdio.h>
#include <string.h>

int estPalindrome(char *chaine) {
    char *ptrStart = chaine;
    char *ptrEnd = chaine + strlen(chaine) - 1;

    while (ptrStart < ptrEnd) {
        if (*ptrStart != *ptrEnd)
            return 0;
        ptrStart++;
        ptrEnd--;
    }
    return 1;
}

int main() {
    char *tests[] = {
        "non",
        "touot",
        "1234321",
        "palindrome",
        "papa",
        "pap"
    };

    int taille = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < taille; i++) {
        if (estPalindrome(tests[i]))
            printf("%s est un palindrome\n", tests[i]);
        else
            printf("%s n'est pas un palindrome\n", tests[i]);
    }

    return 0;
}
