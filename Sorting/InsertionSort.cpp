#include <stdio.h>
#include <iostream>
using namespace std;
void insertionSort(int *, int);
int main()
{
    int size, *arr = NULL;
    cout << "Enter the size of array";
    scanf("%d", &size);
    arr = new int[size];
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, size);
    cout << "Sorted array after Insertion sort:"
         << " ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    arr = NULL;
    return 0;
}

void insertionSort(int *arr, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}