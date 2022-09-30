#include <stdio.h>

void PrintArray(int arr[], int size)
{
    printf("\n\nPrinting all the elements of the array : ");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf(" ");
}

int main()
{
    // range of array
    int range;
    printf("Enter range of the array : ");
    scanf("%d", &range);
    
    // enter data in array
    int arr[range];
    for (int i=0; i<range; i++)
    {
        printf("Enter data for arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
	
	// Bubble Sorting
	for (int i=0; i<range; i++)
	{
        int flag = 0;
		for (int j=0; j<range-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
                flag = 1;
			}
		}
        if (flag==0) break;
	}
	printf("\nPrinting array after Bubble sorting : ");
	for (int i=0; i<range; i++)
	{
		printf("%d ", arr[i]);
	}
    printf("\n\n");
	
    return 0;
}


