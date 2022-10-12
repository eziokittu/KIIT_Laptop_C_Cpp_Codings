// DSA LAB
// Q4) Bubble Sorting

#include <stdio.h>

void BubbleSorting(int *arr, int n){
    for (int i=0; i<n; i++){
        int flag = 0;
		for (int j=0; j<n-1; j++){
			if (*(arr+j) > *(arr+j+1)){
				int temp = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = temp;
                flag = 1;
			}
		}
        if (flag==0) break;
	}
}

void Display(int *arr, int n){
    for (int i=0; i<n; i++){
        printf("%d ", *(arr+i));
    }
}

int main(){
    int n;
    printf("Enter size of the array - ");
    scanf("%d", &n);

    printf("Enter data for array, sorted in ascending order -\n");
    int arr[n];
    for (int i=0; i<n; i++){
        printf("arr [%d] : ", i);
        scanf("%d", arr+i);
    }

    printf("\nPrinting array before sorting -\n");
    Display(arr, n);
    BubbleSorting(arr, n);
    printf("\nPrinting array after sorting -\n");
    Display(arr, n);

    return 0;
}