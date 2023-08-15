#include <stdio.h>
#include <stdlib.h>

void findSecondSmallestAndLargest(int arr[], int n, int *secondSmallest, int *secondLargest) {
    int smallest = arr[0], largest = arr[0];

    // Find the smallest and largest elements in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            *secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] > largest) {
            *secondLargest = largest;
            largest = arr[i];
        }
    }

    // Find the second smallest and second largest elements
    for (int i = 0; i < n; i++) {
        if (arr[i] > smallest && arr[i] < *secondSmallest) {
            *secondSmallest = arr[i];
        } else if (arr[i] < largest && arr[i] > *secondLargest) {
            *secondLargest = arr[i];
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    FILE *file = fopen("file1_1.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int arr[n];
    printf("Reading %d numbers from the file...\n", n);

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    int secondSmallest = arr[0], secondLargest = arr[0];
    findSecondSmallestAndLargest(arr, n, &secondSmallest, &secondLargest);

    printf("Second Smallest: %d\n", secondSmallest);
    printf("Second Largest: %d\n", secondLargest);

    return 0;
}

// Enter the size of the array: 5
// Reading 5 numbers from the file...
// Second Smallest: 2
// Second Largest: 9

// Enter the size of the array: 10
// Reading 10 numbers from the file...
// Second Smallest: -2
// Second Largest: 56

// Enter the size of the array: 15
// Reading 15 numbers from the file...
// Second Smallest: -2
// Second Largest: 81