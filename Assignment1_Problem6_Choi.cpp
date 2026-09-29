#include <iostream>
using namespace std;

int swaps = 0;

void PrintArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SiftDown(int arr[], int root, int size)
{
    while (2 * root + 1 < size)
    {
        int child = 2 * root + 1;
        if (child + 1 < size && arr[child + 1] > arr[child])
        {
            child = child + 1;
        }
        if (arr[root] >= arr[child])
        {
            break;
        }
        int temp = arr[root];
        arr[root] = arr[child];
        arr[child] = temp;

        swaps = swaps + 1;

        root = child;
    }
}

void HeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        SiftDown(arr, i, n);
    }

    cout << "Heap: ";
    PrintArray(arr, n);

    for (int end = n - 1; end > 0; end--)
    {
        int temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;

        SiftDown(arr, 0, end);

        cout << "end = " << end << ": ";
        PrintArray(arr, end);

        cout << "sorted: ";
        PrintArray(arr + end, n - end);
    }
}

int main()
{
    int arr[] = {34, 7, 23, 32, 23, 5, 62, 14, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original: ";
    PrintArray(arr, n);
    HeapSort(arr, n);
    cout << "Sorted: ";
    PrintArray(arr, n);
    cout << "Swaps in SiftDown: " << swaps << endl;
    return 0;
}