#include "hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char guesses[26];
int numberGuesses = 0;
char secret[10];

void chooseWord() {
  FILE *f;

  f = fopen("words.txt", "r");
  if (!f) {
    printf("Error opening words.txt");
    exit(1);
  }

  int nWords;
  fscanf(f, "%d", &nWords);

  srand(time(0));
  int randomic = rand() % nWords;

  for (int i = 0; i < randomic; i++) {
    fscanf(f, "%s", secret);
  }

  fclose(f);
}

void addWord() {
  int add;

  printf("You want to add a new word?\n");
  printf("1. Yes\n0. no\n");
  scanf("%d", &add);

  if (add) {
    char newWord[20];
    printf("Type the word (max 20 carachters) you want to add: ");
    scanf("%s", newWord);

    FILE *f;

    f = fopen("words.txt", "r+");
    if (!f) {
      printf("Error opening words.txt");
      exit(1);
    }

    int numberWords;
    fscanf(f, "%d", &numberWords);
    numberWords++;

    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", numberWords);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", newWord);

    fclose(f);
  }
}

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

  guesses[numberGuesses] = guess;
  numberGuesses++;
}

int isRight(char letter) {
  int find = 0;
  for (int j = 0; j < numberGuesses; j++) {
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

int win() {
  for (int i = 0; i < strlen(secret); i++) {
    if (!isRight(secret[i])) {
      return 0;
    }
  }
  return 1;
}

int isDead() {
  int errors = 0;
  for (int i = 0; i < numberGuesses; i++) {
    int exist = 0;
    if (isRight(secret[i])) {
      exist = 1;
    }
    if (!exist) {
      errors++;
    }
  }
  return errors >= 5;
}

int main() {
  chooseWord();

  opening();

  do {
    printHangman();
    guess();
  } while (!win() && !isDead());
  addWord();

  return 0;
}
