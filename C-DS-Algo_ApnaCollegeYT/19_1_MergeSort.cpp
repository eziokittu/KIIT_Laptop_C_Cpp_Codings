#include <iostream>
using namespace std;

void merge(int arr[], int l, int r, int mid)
{
    int n = mid - l + 1;
    int m = r - mid;

    int a[n];
    int b[m];

    for (int i = 0; i < n; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < m; i++)
    {
        b[i] = arr[mid + i + 1];
    }

    int k = l;

    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }

    while (i < n)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < m)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, r, mid);
    }
}

int main()
{
    int arr[] = {2, 3, 4, 7, 1, 6, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}