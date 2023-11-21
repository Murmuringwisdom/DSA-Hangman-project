#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<time.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6

// Function to print hangman line visuals
void printHangman(int attempts) {
    char *hangman[] = {
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "=========",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "========="
    };

    printf("\n%s\n", hangman[attempts]);
}

// Function to select a random word from a predefined list
char* selectRandomWord() {
    char* words[] = {"google","linkedin","facebook","youtube","srmist","bala","candy","oak","loot","wild","coverage","talkative","letter","prize","prisoner","modest"};
    int numWords = sizeof(words) / sizeof(words[0]);
    int randomIndex = rand() % numWords;
    return words[randomIndex];
}

int main() {
    srand(time(NULL));

    char *wordToGuess = selectRandomWord();
    int wordLength = strlen(wordToGuess);

    char *guessedWord = (char *)malloc(wordLength + 1);
    memset(guessedWord, '_', wordLength);
    guessedWord[wordLength] = '\0';

    int attempts = 0;
    int correctGuesses = 0;

    printf("Welcome to Hangman!\n");

    while (attempts < MAX_TRIES && correctGuesses < wordLength) {
        printf("\nWord to Guess: %s\n", guessedWord);

        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        int letterFound = 0;
        for (int i = 0; i < wordLength; i++) {
            if (wordToGuess[i] == guess && guessedWord[i] != guess) {
                guessedWord[i] = guess;
                correctGuesses++;
                letterFound = 1;
            }
        }

        if (!letterFound) {
            attempts++;
            printf("Incorrect guess. Tries left: %d\n", MAX_TRIES - attempts);
            printHangman(attempts);
        }
    }

    if (correctGuesses == wordLength) {
        printf("\nCongratulations! You guessed the word: %s\n", wordToGuess);
    } else {
        printf("\nYou lost! The word was: %s\n", wordToGuess);
    }

    free(guessedWord);
    
    return 0;
}