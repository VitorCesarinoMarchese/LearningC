#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRYES 5

int main() {

  printf("***********************\n");
  printf("The guessing game!\n");
  printf("***********************\n");

  int seed = time(0);
  srand(seed);
  int secretNumber = rand() % 100;

  // aways define a value before using a variable
  int guess;
  double points = 1000;

  int isReady;
  while (1) {
    printf("Are you ready?\n");
    printf("1. Yes\n0. No\n");
    scanf("%d", &isReady);
    printf("%d\n", isReady != 1);
    if (isReady != 1 && isReady != 0) {
      printf("You need to type 1 for yes or 0 for no!\n");
    } else {
      break;
    }
  }

  if (isReady) {
    printf("Nice choice you have %d chances to guess the secret number\n",
           TRYES);

    for (int i = 1; i <= TRYES; i++) {
      printf("This is your %d/%d guess\n", i, TRYES);
      printf("What is your guess?\n");
      scanf("%d", &guess);

      if (guess < 0) {
        printf("Your guess needs to be a positive number\n");
        i--;
        continue;
      }

      printf("Your guess was %d\n", guess);

      int isCorrect = secretNumber == guess;
      if (isCorrect) {
        printf("You are a pro! You find the secret!!!\n");
        printf("Fell the future!\n");
        break;
      } else {
        double penality;
        penality = abs(guess - secretNumber) / 2.0;
        printf("You didn't find the secret!!!\n");
        printf("But I will give you a hint noob!\n");

        int isHigher = guess > secretNumber;
        if (isHigher) {
          printf("Your guess is higher than the secret\n");
        } else {
          printf("Your guess is lower than the secret\n");
        }
        printf("Fell the gap!\n");
        points = points - (penality);
      }
    }
    printf("You have %.1f points\n", points);
  } else {
    printf("Ok, see you later!\n");
  }
  return 0;
}
