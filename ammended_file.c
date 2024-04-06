#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char buffer[100];

    // Open input.txt for reading
    inputFile = fopen("C:\\Users\\kidsa\\Searches\\dsac\\ICS2371\\input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    // Open output.txt for appending
    outputFile = fopen("C:\\Users\\kidsa\\Searches\\dsac\\ICS2371\\output.txt", "a");
    if (outputFile == NULL) {
        printf("Error opening output.txt\n");
        fclose(inputFile);
        return 1;
    }

    // Read from input file and write to output file
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        fputs(buffer, outputFile);
    }

    // Close input file
    fclose(inputFile);

    // Prompt the user to enter additional text
    printf("Enter some additional text: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Write the additional text to output.txt
    fputs(buffer, outputFile);

    // Close output file
    fclose(outputFile);

    printf("Additional text appended to output.txt successfully.\n");
    return 0;
}

