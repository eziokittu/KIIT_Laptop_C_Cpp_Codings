#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_filename> <destination_filename>\n", argv[0]);
        return 1;
    }

    FILE *sourceFile = fopen(argv[1], "r");
    FILE *destinationFile = fopen(argv[2], "w");

    if (sourceFile == NULL || destinationFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int a, b;
    while (fscanf(sourceFile, "%d %d", &a, &b) == 2) {
        int result = gcd(a, b);
        fprintf(destinationFile, "The GCD of %d and %d is %d\n", a, b, result);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    // Displaying the content of the output file
    destinationFile = fopen(argv[2], "r");
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
