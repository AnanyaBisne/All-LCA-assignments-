#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourcePath[100], destPath[100];
    int ch;


    printf("Enter source file path: ");
    scanf("%99s", sourcePath);

    printf("Enter destination file path: ");
    scanf("%99s", destPath);


    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Error: Unable to open source file.\n");
        return 1;
    }


    destFile = fopen(destPath, "w");
    if (destFile == NULL) {
        printf("Error: Unable to open destination file.\n");
        fclose(sourceFile); // Clean up already opened file
        return 1;
    }


    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");


    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
