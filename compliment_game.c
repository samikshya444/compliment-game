#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // List of compliments
    char compliments[][20] = {
        "lovely", "smart", "kind", "amazing",
        "talented", "brave", "sweet", "cool"
    };

    int totalWords = sizeof(compliments) / sizeof(compliments[0]);

    // Pick a random compliment
    char word[20];
    strcpy(word, compliments[rand() % totalWords]);

    int len = strlen(word);

    char display[20];
    for (int i = 0; i < len; i++) {
        display[i] = '_';   // hide letters
    }
    display[len] = '\0';

    int correct = 0;
    char guess;
    int attempts = 7;  // hearts / lives

    printf("💖 Welcome to the Guess-the-Compliment Game! 💖\n");
    printf("Guess the letters and reveal your compliment!\n\n");

    while (attempts > 0 && correct < len) {
        printf("Word: ");
        for (int i = 0; i < len; i++) {
            printf("%c ", display[i]);
        }
        printf("\n");

        printf("Enter a letter: ");
        scanf(" %c", &guess);

        int found = 0;

        for (int i = 0; i < len; i++) {
            if (word[i] == guess && display[i] == '_') {
                display[i] = guess;
                correct++;
                found = 1;
            }
        }

        if (found) {
            printf("✨ Correct! +1 charm point!\n\n");
        } else {
            attempts--;
            printf("❌ Wrong guess! Attempts left: %d\n\n", attempts);
        }
    }

    if (correct == len) {
        printf("\n🎉 You guessed the word: %s\n", word);
        printf("💖 Reward: You're %s too! 💖\n", word);
    } else {
        printf("\n😢 Out of attempts! The word was: %s\n", word);
        printf("But you're still amazing for trying! 💞\n");
    }

    return 0;
}
