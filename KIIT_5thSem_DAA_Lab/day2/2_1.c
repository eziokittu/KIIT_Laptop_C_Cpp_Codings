
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimal, FILE *outputFile) {
    if (decimal == 0) {
        return;
    }

    decimalToBinary(decimal / 2, outputFile);
    fprintf(outputFile, "%d", decimal % 2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <source_filename> <destination_filename>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *sourceFile = fopen(argv[2], "r"); // file2_1_in.dat
    FILE *destinationFile = fopen(argv[3], "w"); // file2_1_out.dat

    if (sourceFile == NULL || destinationFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int decimal;
        if (fscanf(sourceFile, "%d", &decimal) == 1) {
            fprintf(destinationFile, "The binary equivalent of %d is ", decimal);
            decimalToBinary(decimal, destinationFile);
            fprintf(destinationFile, "\n");
        } else {
            printf("Error reading decimal from source file.\n");
            break;
        }
    }

    fclose(sourceFile);
    fclose(destinationFile);

    // Displaying the content of the output file
    destinationFile = fopen(argv[3], "r");
    if (destinationFile == NULL) {
        printf("Error opening destination file for reading.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), destinationFile)) {
        printf("%s", line);
    }

    fclose(destinationFile);

    return 0;
}
