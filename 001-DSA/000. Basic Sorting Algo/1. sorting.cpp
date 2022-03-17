#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10

// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order, at end of each iteration the largest element goes to the end
void bubbleSort(int *arr, int arrLen)
{
    for (int i = 0; i < arrLen - 1; i++)
    {
        for (int j = 0; j < arrLen - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

// Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.
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
