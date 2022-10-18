#include <iostream>
#include <cstdlib>
using namespace std;

// Linear Search
int LinearSearch(int arr[], int size, int search)
{
    for (int i=0; i<size; i++){
        if (arr[i] == search)
        {
            return i;
        }
    }
    cout << " [Data not available]";
    return -1;
}

// Binary search (Array needs to be sorted in ascending order)
int BinarySearch(int arr[], int size, int search)
{
    int start=0, end = size, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        
        if (search == arr[mid]) return mid;
        else if (search < arr[mid]) end = mid-1;
        else if (search > arr[mid]) start = mid+1;
    }
    return -1;
}

void PrintArray(int arr[], int size)
{
    cout << "\n\nPrinting all the elements of the array : ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // range of array
    int range;
    cout << "Enter range of the array : ";
    cin >> range;
    
    // enter data in array
    int arr[range];
    cout << "Enter data for the array : \n";
    for (int i=0; i<range; i++)
    {
        cout << "Enter data for arr[" << i << "] : ";
        cin >> arr[i];
    }
    
    // Sum and Average of all elements of the array
    int sum=0;
    for (int i=0; i<range; i++)
    {
        sum += arr[i];
    }
    cout << "\nSum of all elements of the array : " << sum;
    cout << "\nAverage of all the elements : " << (sum/(float)range);
    
    // Printing the array
    PrintArray(arr, range);
    
    // Which data to search
    int search;
    cout << "\nWhich data do you want to search for : ";
    cin >> search;
    
    // Linear Search
    cout << "\nAfter Linear Search - the data "<< search << " is at INDEX : " << LinearSearch(arr, range, search);
    
    // Selection Sorting
    for (int i=0; i<range-1; i++)
    {
    	for (int j=i+1; j<range; j++)
    	{
    		if (arr[i] > arr[j])
    		{
    			int temp = arr[j];
    			arr[j] = arr[i];
    			arr[i] = temp;
			}
		}
	}
	cout << "\n\nPrinting array after Selection sorting : ";
	for (int i=0; i<range; i++)
	{
		cout << arr[i] << " ";
	}
	
	// Bubble Sorting
	for (int i=0; i<range; i++)
	{
		for (int j=0; j<range-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	cout << "\n\nPrinting array after Bubble sorting : ";
	for (int i=0; i<range; i++)
	{
		cout << arr[i] << " ";
	}
	
	// Binary Search - needs a sorted array
    cout << "\nAfter Binary Search - the data "<< search << " is at INDEX : " << BinarySearch(arr, range, search);
    
    
    return 0;
}


