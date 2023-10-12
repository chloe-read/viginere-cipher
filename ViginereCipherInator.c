#include <stdio.h>
#include <string.h>
#include <ctype.h>

int charToInt(char c) {
    return tolower(c) - 'a';
}

char intToChar(int i) {
    return (char)(i + 'a');
}

void vigenereCipher(char* unencrypted, char* key, int encrypt) {
    char encrypted[strlen(unencrypted)];
    int keyLength = strlen(key);
    int i, j;

    for (i = 0, j = 0; unencrypted[i] != '\0'; ++i) {
        char c = unencrypted[i];
        if (isalpha(c)) {
            int x;
            if (encrypt) {
                x = charToInt(c) + charToInt(key[j % keyLength]);
            } else {
                x = charToInt(c) - charToInt(key[j % keyLength]);
                if (x < 0) {
                    x += 26;
                }
            }
            encrypted[i] = intToChar(x % 26);
            ++j;
        } else {
            encrypted[i] = c;
        }
    }
    encrypted[i] = '\0';

    printf("Encrypted format: %s\n", encrypted);
}

int main() {
    char input[100];
    char key[100];
    char choice[2];

    while (1) {
        printf("Encrypt/Decrypt? (e/d): ");
        scanf("%1s", choice);

        if (choice[0] == 'e' || choice[0] == 'd') {
            int encrypt = (choice[0] == 'e');
            getchar(); 

            printf("Enter passkey phrase/word (any numbers, spaces, or special characters will be removed): ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = '\0'; 

            printf("Enter text to be encoded: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0'; 

            vigenereCipher(input, key, encrypt);

            printf("Encrypt/Decrypt another? (y/n): ");
            scanf("%1s", choice);
            if (choice[0] == 'n') {
                break;
            }
        } else {
            printf("Please input either 'e' or 'd'.\n");
        }
    }

    return 0;
}
