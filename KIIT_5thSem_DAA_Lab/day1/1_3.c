#include <stdio.h>
#include <stdlib.h>

void findDuplicates(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }

    printf("Total number of duplicate values = %d\n", count);
}

int findMostRepeatingElement(int arr[], int n) {
    int maxCount = 0;
    int mostRepeatingElement = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostRepeatingElement = arr[i];
        }
    }

    return mostRepeatingElement;
}

int main() {
    int n;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    FILE *file = fopen("file1_3.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int arr[n];
    printf("The content of the array: ");

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
        printf("%d ", arr[i]);
    }

    fclose(file);
    printf("\n");

    findDuplicates(arr, n);
    int mostRepeating = findMostRepeatingElement(arr, n);
    printf("The most repeating element in the array = %d\n", mostRepeating);

    return 0;
}
