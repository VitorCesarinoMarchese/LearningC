# Guessing Game (C)

A simple number guessing game built in C to practice core language concepts and control structures.

## 📌 Features
- Randomly generates a secret number between 0 and 99.
- Player has **5 attempts** to guess the correct number.
- Provides hints if the guess is higher or lower than the secret.
- Calculates and displays a score based on accuracy.

## 🛠️ What I Learned
- **Data Types:** Using `int` and `double` to store numbers and fractional scores.
- **Standard I/O (`stdio.h`):** Printing and reading input with `printf` and `scanf`.
- **Time Functions (`time.h`):** Seeding the random number generator with the current time.
- **Randomization (`rand`/`srand`):** Generating unpredictable secret numbers.
- **Loops:** Using `for` and `while` to control game flow and validate input.
- **Constants (`#define`):** Creating named constants for configuration (e.g., `TRYES` for number of attempts).
- **Conditional Statements (`if`/`else`):** Handling game logic, input validation, and hints.

## ▶️ How to Play
1. Compile the program:
   ```bash
   gcc main.c -o guessing_game
   ```
2. Run it:
   ```bash
   ./guessing_game
   ```
3. Choose to start the game or exit.
4. Enter guesses between 0 and 99:
   - If you guess correctly, you win 🎉
   - If you use all attempts, you lose 💀
5. Your score is displayed at the end based on how close your guesses were.

## 📂 Files
- `main.c`: Contains all the game logic.

## ✅ Next Steps / Possible Improvements
- Allow the user to set the range of numbers.
- Add difficulty levels with different attempt limits.
- Save high scores to a file.
- Improve input validation for non-numeric entries.
