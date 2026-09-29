#include <iostream>
using namespace std;

int comparisons = 0;
int swaps = 0;

// Function 1: Prints the n elements of arr on one line, separated by spaces
void PrintArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function 2: Sorts arr in ascending order from least to greatest
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons = comparisons + 1;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps = swaps + 1;
                swapped = true;
            }
        }

        cout << "Pass " << i + 1 << ": ";
        PrintArray(arr, n);


        // Stop any operations if the array is presorted
        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial: ";
    PrintArray(arr, n);
    BubbleSort(arr, n);
    cout << "Sorted: ";
    PrintArray(arr, n);
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    return 0;
}