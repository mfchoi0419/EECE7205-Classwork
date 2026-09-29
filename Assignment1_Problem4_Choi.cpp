#include <iostream>
using namespace std;

int comparisons = 0;
int depth = 0;
bool firstpartition = true;

void PrintArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisons = comparisons + 1;
        if (arr[j] <= pivot)
        {
            i = i + 1;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
            if (firstpartition)
            {
            cout << "i: " << i << endl;
            cout << "j: " << j << endl;
            PrintArray(arr, high + 1);
            }
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    if (firstpartition)
    {
        PrintArray(arr, high + 1);
        cout << "Final pivot position: " << i + 1 << endl;
    }
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        for (int i = 0; i < depth; i++)
        {
            cout << "   ";
        }

        cout << "Pivot: " << arr[high] << ": ";
        PrintArray(arr + low, high - low + 1);

        int p = Partition(arr, low, high);

        firstpartition = false;

        depth = depth + 1;

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);

        depth = depth - 1;
    }
}

int main()
{
    int arr[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original: ";
    PrintArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted: ";
    PrintArray(arr, n);
    cout << "Comparisons: " << comparisons << endl;
    return 0;
}