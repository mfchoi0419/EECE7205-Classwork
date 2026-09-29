#include <iostream>
using namespace std;

int comparisons = 0;
int final_merge_comparisons = 0;

void PrintArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int x = 0; x < n1; x++)
    {
        L[x] = arr[low + x];
    }
    for (int x = 0; x < n2; x++)
    {
        R[x] = arr[mid + 1 + x];
    }

    int i = 0; int j = 0; int k = low;
    while (i < n1 && j < n2)
    {
        comparisons = comparisons + 1;

        if (low == 0 && high == 7)
        {
            final_merge_comparisons = final_merge_comparisons + 1;
        }

        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i = i + 1;
        }
        else
        {
            arr[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i = i + 1;
        k = k + 1;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
    delete [] L;
    delete [] R;
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        cout << "split: ";
        PrintArray(arr + low, mid - low + 1);

        cout << "split: ";
        PrintArray(arr + mid + 1, high - mid);

        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);

        cout << "merged: ";
        PrintArray(arr + low, high - low + 1);
    }
}

int main()
{
    int arr[] = {62, 34, 32, 23, 19, 14, 7, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original: ";
    PrintArray(arr, n);
    MergeSort(arr, 0, n - 1);
    cout << "Sorted: ";
    PrintArray(arr, n);
    cout << "Comparisons: " << comparisons << " (final merge: " << final_merge_comparisons << ")" << endl;
    return 0;
}
