#include <iostream>
using namespace std;

int comparisons = 0;
int swaps = 0;

void PrintArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int arr[], int n)
{
    
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons = comparisons + 1;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        cout << "Pass " << i + 1 << ": min = " << arr[minIndex] << " at index " << minIndex << " -> ";

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps = swaps + 1;
        }
        PrintArray(arr, n);
    }
}

int main()
{
    int arr[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original: ";
    PrintArray(arr, n);
    SelectionSort(arr, n);
    cout << "Sorted: ";
    PrintArray(arr, n);
    cout << "Comparisons: " << comparisons << " Swaps: " << swaps << endl;
    return 0;
}