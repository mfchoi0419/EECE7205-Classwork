#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

int comparisons = 0;
int swaps = 0;
int shifts = 0;
// int depth = 0;
// bool firstpartition = true;
int final_merge_comparisons = 0;

// Since all the counters are global variables, you have to reset them before every
// sorting operation or else it'll return the total number of comparisons, swaps, shifts,
// and final_merge_comparisons of every operation instead of the individual operations.
void ResetCounters()
{
    comparisons = 0;
    swaps = 0;
    shifts = 0;
    final_merge_comparisons = 0;
}

// Prints the n elements of arr on one line, separated by spaces
void PrintArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Problem 1: Bubble Sort
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

        // cout << "Pass " << i + 1 << ": ";
        // PrintArray(arr, n);

        if (swapped == false)
        {
            break;
        }
    }
}

// Problem 2: Insertion Sort
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
        // cout << "i = " << i << ", key = " << key << endl;
        // PrintArray(arr, n);
    }
}

// Problem 3: Selection Sort
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
        // cout << "Pass " << i + 1 << ": min = " << arr[minIndex] << " at index " << minIndex << " -> ";

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps = swaps + 1;
        }
        // PrintArray(arr, n);
    }
}

// Problem 4: Quick Sort
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
            
            //if (firstpartition)
            //{
            //cout << "i: " << i << endl;
            //cout << "j: " << j << endl;
            //PrintArray(arr, high + 1);
            //}
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    //if (firstpartition)
    //{
    //    PrintArray(arr, high + 1);
    //    cout << "Final pivot position: " << i + 1 << endl;
    //}
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //for (int i = 0; i < depth; i++)
        //{
        //    cout << "   ";
        //}

        //cout << "Pivot: " << arr[high] << ": ";
        //PrintArray(arr + low, high - low + 1);

        int p = Partition(arr, low, high);

        // firstpartition = false;

        // depth = depth + 1;

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);

        // depth = depth - 1;
    }
}

// Problem 5: Merge Sort
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
    delete[] L;
    delete[] R;
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        // cout << "split: ";
        // PrintArray(arr + low, mid - low + 1);

        // cout << "split: ";
        // PrintArray(arr + mid + 1, high - mid);

        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);

        // cout << "merged: ";
        // PrintArray(arr + low, high - low + 1);
    }
}

// Problem 6: Heap Sort
void SiftDown(int arr[], int root, int size)
{
    while (2 * root + 1 < size)
    {
        int child = 2 * root + 1;

        if (child + 1 < size)
        {
            comparisons = comparisons + 1;

            if (arr[child + 1] > arr[child])
            {
                child = child + 1;
            }
        }

        comparisons = comparisons + 1;

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

    // cout << "Heap: ";
    // PrintArray(arr, n);

    for (int end = n - 1; end > 0; end--)
    {
        int temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;

        SiftDown(arr, 0, end);

        // cout << "end = " << end << ": ";
        // PrintArray(arr, end);

        // cout << "sorted: ";
        // PrintArray(arr + end, n - end);
    }
}

// Runtime function to test each sorting function on random arrays of 1000, 5000,
// and 10000 integers between 1 and 100,000
// Prints first 10 elements of each sorted array to check that the sorting
// is correct
void TestRuntime(int n)
{
    int *randomArr = new int[n];

    for (int i = 0; i < n; i++)
    {
        randomArr[i] = rand() % 100000 + 1;
    }
    
    int *bubble = new int[n];
    int *insertion = new int[n];
    int *selection = new int[n];
    int *quick = new int[n];
    int *merge = new int[n];
    int *heap = new int[n];

    for (int i = 0; i < n; i++)
    {
        bubble[i] = randomArr[i];
        insertion[i] = randomArr[i];
        selection[i] = randomArr[i];
        quick[i] = randomArr[i];
        merge[i] = randomArr[i];
        heap[i] = randomArr[i];
    }

    cout << endl;
    cout << "Array size: " << n << endl;

    ResetCounters();
    auto start = high_resolution_clock::now();
    BubbleSort(bubble, n);
    auto stop = high_resolution_clock::now();
    auto bubbleTime = duration_cast<microseconds>(stop - start).count();
    cout << "Bubble Sort: " << bubbleTime << " microseconds" << endl;

    ResetCounters();
    start = high_resolution_clock::now();
    InsertionSort(insertion, n);
    stop = high_resolution_clock::now();
    auto insertionTime = duration_cast<microseconds>(stop - start).count();
    cout << "Insertion Sort: " << insertionTime << " microseconds" << endl;

    ResetCounters();
    start = high_resolution_clock::now();
    SelectionSort(selection, n);
    stop = high_resolution_clock::now();
    auto selectionTime = duration_cast<microseconds>(stop - start).count();
    cout << "Selection Sort: " << selectionTime << " microseconds" << endl;

    ResetCounters();
    start = high_resolution_clock::now();
    quickSort(quick, 0, n - 1);
    stop = high_resolution_clock::now();
    auto quickTime = duration_cast<microseconds>(stop - start).count();
    cout << "Quick Sort: " << quickTime << " microseconds" << endl;

    ResetCounters();
    start = high_resolution_clock::now();
    MergeSort(merge, 0, n - 1);
    stop = high_resolution_clock::now();
    auto mergeTime = duration_cast<microseconds>(stop - start).count();
    cout << "Merge Sort: " << mergeTime << " microseconds" << endl;

    ResetCounters();
    start = high_resolution_clock::now();
    HeapSort(heap, n);
    stop = high_resolution_clock::now();
    auto heapTime = duration_cast<microseconds>(stop - start).count();
    cout << "Heap Sort: " << heapTime << " microseconds" << endl;

    cout << endl;
    cout << "First 10 elements after sorting:" << endl;

    cout << "Bubble: ";
    PrintArray(bubble, 10);

    cout << "Insertion: ";
    PrintArray(insertion, 10);

    cout << "Selection: ";
    PrintArray(selection, 10);

    cout << "Quick: ";
    PrintArray(quick, 10);

    cout << "Merge: ";
    PrintArray(merge, 10);

    cout << "Heap: ";
    PrintArray(heap, 10);

    delete[] randomArr;
    delete[] bubble;
    delete[] insertion;
    delete[] selection;
    delete[] quick;
    delete[] merge;
    delete[] heap;
}

// main() for testing runtime of random array
int main()
{
    TestRuntime(1000);
    TestRuntime(5000);
    TestRuntime(10000);

    return 0;
}

// main() for counting comparisons
/*
int main()
{
    int arr[] = {62, 34, 32, 23, 19, 14, 7, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int bubble[8];
    int insertion[8];
    int selection[8];
    int quick[8];
    int merge[8];
    int heap[8];

    for (int i = 0; i < n; i++)
    {
        bubble[i] = arr[i];
        insertion[i] = arr[i];
        selection[i] = arr[i];
        quick[i] = arr[i];
        merge[i] = arr[i];
        heap[i] = arr[i];
    }

    ResetCounters();
    BubbleSort(bubble, n);
    cout << "Bubble Sort: " << comparisons << " comparisons, " << swaps << " swaps" << endl;

    ResetCounters();
    InsertionSort(insertion, n);
    cout << "Insertion Sort: " << comparisons << " comparisons, " << shifts << " shifts" << endl;

    ResetCounters();
    SelectionSort(selection, n);
    cout << "Selection Sort: " << comparisons << " comparisons, " << swaps << " swaps" << endl;

    ResetCounters();
    quickSort(quick, 0, n - 1);
    cout << "Quick Sort: " << comparisons << " comparisons" << endl;

    ResetCounters();
    MergeSort(merge, 0, n - 1);
    cout << "Merge Sort: " << comparisons << " comparisons, " << final_merge_comparisons << " final merge comparisons" << endl;

    ResetCounters();
    HeapSort(heap, n);
    cout << "Heap Sort: " << comparisons << " comparisons, " << swaps << " swaps" << endl;
}
*/