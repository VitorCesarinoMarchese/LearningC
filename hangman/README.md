# Hangman (C)

A simple terminal-based Hangman game built to learn the fundamentals of the C programming language.

## 📌 Features
- Random word selection from a `words.txt` file.
- Ability to add new words to the list during gameplay.
- Keeps track of user guesses and displays correct letters.
- Ends game when the player either guesses the word or reaches the maximum number of allowed mistakes.

## 🛠️ What I Learned
- **Strings in C:** How to create and manipulate strings.
- **Pointers:** Passing and modifying data efficiently.
- **Functions:** Organizing code into reusable, readable blocks.
- **File Handling:** Reading and writing to files with `fopen`, `fscanf`, `fprintf`, and `fseek`.
- **Randomization:** Using `rand()` and `srand()` to select random words.
- **Game Logic:** Handling guesses, tracking errors, and checking win/loss conditions.
- **Header Files:** Creating a separate `.h` file (`hangman.h`) to declare functions and organize code, improving modularity and maintainability.

## 📂 Files
- `main.c`: The main game logic.
- `hangman.h`: Header file for function declarations.
- `words.txt`: Contains the list of words.  
  - The first line is the number of words.  
  - Each following line is a word.

Example `words.txt`:
```
3
apple
banana
grape
```

## ▶️ How to Play
1. Compile the program:
   ```bash
   gcc main.c -o hangman
   ```
2. Run it:
   ```bash
   ./hangman
   ```
3. Guess letters until you either:
   - Reveal the full word and win 🎉
   - Make 5 mistakes and lose 💀
4. At the end, you can add a new word to the game’s word list.
