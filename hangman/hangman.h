#define WORD_SIZE 10
#define MAX_ERRORS 5
#define MAX_GUESSES 26

int wrongGuesses();
void opening();
void guess();
int isRight(char letter);
void printHangman();
int win();
int isDead();
void chooseWord();
void addWord();
