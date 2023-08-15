#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter data for array:\n");
    for (int i=0; i<n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &a[i]);
    }

    // prefix sum array
    printf("\nThe prefix sum array is: ");
    int sum=0;
    for (int i=0; i<n; i++){
        sum = sum+a[i];
        a[i]=sum;
        printf("%d ", a[i]);
    }

    return 0;
}

// Enter the size of the array: 4
// Enter data for array:
// arr[0]: 1
// arr[1]: 2
// arr[2]: 3
// arr[3]: 4
// The prefix sum array is: 1 3 6 10

// Enter the size of the array: 6
// Enter data for array:
// arr[0]: 10 15 1 2 100 7
// arr[1]: arr[2]: arr[3]: arr[4]: arr[5]:
// The prefix sum array is: 10 25 26 28 128 135