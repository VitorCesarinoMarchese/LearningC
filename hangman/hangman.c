#include <stdio.h>
#include <string.h>

int main() {
  char secret[10];
  sprintf(secret, "melancia");

  int win = 0;
  int dead = 0;

  char guesses[26];
  int tryes = 0;

  do {
    for (int i = 0; i < strlen(secret); i++) {
      int find = 0;
      for (int j = 0; j < tryes; j++) {
        if (guesses[j] == secret[i]) {
          find = 1;
          break;
        }
      }
      if (find) {
        printf("%c", secret[i]);
      } else {
        printf("_ ");
      }
    }
    printf("\n");

    printf("=======================\n");

    printf("What is your guess?\n");
    char guess;
    scanf(" %c", &guess);
    printf("=======================\n");
    printf("Your guess was: %c\n", guess);

    if (guess == '!') {
      printf("You exit the game ;-;\n");
      break;
    }

    guesses[tryes] = guess;
    tryes++;
  } while (!win && !dead);

  return 0;
}
