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

void printHangman() {
  for (int i = 0; i < strlen(secret); i++) {
    if (isRight(secret[i])) {
      printf("%c", secret[i]);
    } else {
      printf("_");
    }
  }
  printf("\n");
}

int main() {
  sprintf(secret, "melancia");

  int win = 0;
  int dead = 0;

  opening();

  do {
    printHangman();
    guess();
  } while (!win && !dead);

  return 0;
}
