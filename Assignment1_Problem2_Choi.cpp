#include <iostream>
using namespace std;

int comparisons = 0;
int shifts = 0;

// Function 1: Prints the n elements of arr on one line, separated by spaces
void PrintArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function 2: Sorts the arr in place in ascending order from least to greatest value
void InsertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            comparisons = comparisons + 1;

            arr[j + 1] = arr[j];
            shifts = shifts + 1;
            j = j - 1;
        }

        if (j>= 0)
        {
            comparisons = comparisons + 1;
        }
        arr[j + 1] = key;
        cout << "i = " << i << ", key = " << key << endl;
        PrintArray(arr, n);
    }
}

int main()
{
    int arr[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original: ";
    PrintArray(arr, n);
    InsertionSort(arr, n);
    cout << "Sorted: ";
    PrintArray(arr, n);
    cout << "Comparisons: " << comparisons << ", Shifts: " << shifts << endl;
    return 0;
}