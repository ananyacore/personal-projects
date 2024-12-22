#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Error handling for command-line arguments
    if (argc != 2) {
        printf("Please enter a key of 26 unique alphabets in the desired order.\n");
        return 1;
    }

    char *key = argv[1];

    // Check if the key is exactly 26 characters
    if (strlen(key) != 26) {
        printf("Key must contain 26 unique alphabets.\n");
        return 1;
    }

    // Validate the key contains only alphabets and no duplicates
    int alphabet_count[26] = {0};
    for (int i = 0; i < 26; i++) {
        if (!isalpha(key[i])) {
            printf("Key must contain alphabets only.\n");
            return 1;
        }

        int index = tolower(key[i]) - 'a';
        alphabet_count[index]++;
        if (alphabet_count[index] > 1) {
            printf("Please ensure alphabets are not repeated.\n");
            return 1;
        }
    }

    // Input plaintext
    char plt[256];
    printf("plaintext: ");
    fgets(plt, sizeof(plt), stdin);

    // Cipher the plaintext
    for (int i = 0; plt[i] != '\0'; i++) {
        if (islower(plt[i])) {
            plt[i] = tolower(key[plt[i] - 'a']);
        } else if (isupper(plt[i])) {
            plt[i] = toupper(key[plt[i] - 'A']);
        }
    }

    printf("ciphertext: %s", plt);
    return 0;
}
