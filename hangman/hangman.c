#include <stdio.h>
#include <string.h>

char guesses[26];
int tryes = 0;
char secret[10];

void opening() {
  printf("*************************\n");
  printf("       Hangman game      \n");
  printf("*************************\n\n");
}

void guess() {
  printf("=======================\n");
  printf("What is your guess?\n");

  char guess;
  scanf(" %c", &guess);

  printf("=======================\n");
  printf("Your guess was: %c\n", guess);

  guesses[tryes] = guess;
  tryes++;
}

int isRight(char letter) {
  int find = 0;
  for (int j = 0; j < tryes; j++) {
    if (guesses[j] == letter) {
      return 1;
      break;
    }
  }
  return 0;
}

void printHangman(int *erros, int *rights) {
  int right = 0;
  for (int i = 0; i < strlen(secret); i++) {
    if (isRight(secret[i])) {
      right++;
      (*rights)++;
      printf("%c", secret[i]);
    } else {
      printf("_");
    }
  }
  if (!right) {
    (*erros)++;
  }
  printf("\n");
}

int main() {
  sprintf(secret, "melancia");

  int win = 0;
  int dead = 0;

  int erros = 0;
  int rights = 0;

  opening();

  do {
    printHangman(&erros, &rights);
    guess();
    printf("%d", rights);
    if (rights == strlen(secret)) {
      win = 1;
    }
    if (erros == 5) {
      dead = 1;
    }
  } while (!win && !dead);

  return 0;
}
