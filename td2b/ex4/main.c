#include <stdio.h>

int main(){
  int response;
  scanf("%d", &response);
  switch(response){
    case 1:
      printf("Bonne réponse\n");
      break;
    case 2:
    case 3:
      printf("Mauvaise réponse\n");
      break;
    default:
      printf("Réponse inattendue\n");
  }
}