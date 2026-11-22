#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Custom implementation of strrev for Linux GCC
void custom_strrev(char *str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Custom implementation of strupr for Linux GCC
void custom_strupr(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Custom implementation of strlwr for Linux GCC
void custom_strlwr(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    int choice;
    char str1[100];
    char str2[100];

    do {
        printf("\n========================================\n");
        printf("      MENU-DRIVEN STRING OPERATIONS      \n");
        printf("========================================\n");
        printf("1. Find length of string (strlen)\n");
        printf("2. Copy string (strcpy)\n");
        printf("3. Concatenate string (strcat)\n");
        printf("4. Compare string (strcmp)\n");
        printf("5. Reverse string (strrev)\n");
        printf("6. Convert string to uppercase (strupr)\n");
        printf("7. Convert string to lowercase (strlwr)\n");
        printf("8. Exit\n");
        printf("========================================\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);
        getchar(); // Clear the trailing newline from the buffer

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                strcpy(str2, str1);
                printf("Copied destination string (str2): %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter second string to append: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                int res = strcmp(str1, str2);
                if (res == 0)
                    printf("Result: Both strings are identical.\n");
                else if (res > 0)
                    printf("Result: First string is lexicographically greater.\n");
                else
                    printf("Result: Second string is lexicographically greater.\n");
                break;

            case 5:
                printf("Enter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                custom_strrev(str1);
                printf("Reversed string: %s\n", str1);
                break;

            case 6:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                custom_strupr(str1);
                printf("Uppercase string: %s\n", str1);
                break;

            case 7:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                custom_strlwr(str1);
                printf("Lowercase string: %s\n", str1);
                break;

            case 8:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select a option between 1 and 8.\n");
        }
    } while (choice != 8);

    return 0;
}
