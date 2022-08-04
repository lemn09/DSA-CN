#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10

// simplest sorting algo, compare adjacent elements, 
// after one full pass of array heaviest(largest) element is at end
// T(n): O(n^2)
// best case: O(n)(if flag variable is used)
// inplace, adaptive(if flag var is used), stable
void bubbleSort(int *arr, int arrLen)
{
    for (int i = 0; i < arrLen - 1; i++)
    {
        bool flag= true;
        for (int j = 0; j < arrLen - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap stl
                swap(arr[j], arr[j+1]);
                flag= false;
            }
        }
        // if no swaps occured => sorted array
        if(flag)    return;
    }
}

// Selection sort works by taking the smallest element in an unsorted array and bringing it to the front.
void selectionSort(int *arr, int arrLen)
{
    for (int i = 0; i < arrLen - 1; i++)
    {
        int least = arr[i];
        int pos = i;
        for (int j = i; j < arrLen; j++)
        {
            if (arr[j] < least)
            {
                pos = j;
                least = arr[j];
            }
        }
        arr[pos] = arr[i];
        arr[i] = least;
    }
}

// in insertion sort we compare element at ith index with elements from i-1 to 0, and place the ith index element at appropriate position
// T(n): O(n^2), Worst case: reverse sorted array, Best case: sorted array(no swaps only comparisons)
// in-place sorting algo, stable algo
void insertionSort(int *arr, int arrLen)
{
    for (int i = 1; i < arrLen; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

void print(int *arr, int arrLen)
{
    cout << "Array: ";
    for (int i = 0; i < arrLen; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int arr[SIZE] = {};
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Before\n";
    print(arr, sizeof(arr) / sizeof(int));
    cout << "Size: " << sizeof(arr) / sizeof(int) << endl;
    // bubbleSort(arr, sizeof(arr)/sizeof(int));
    // selectionSort(arr, sizeof(arr)/sizeof(int));
    insertionSort(arr, sizeof(arr) / sizeof(int));
    cout << "\nAfter\n";
    print(arr, sizeof(arr) / sizeof(int));
    return 0;
}
