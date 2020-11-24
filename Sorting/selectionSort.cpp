#include <stdio.h>
#include <iostream>
using namespace std;
void selectionSort(int *, int);
void swap(int *, int, int);
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
    selectionSort(arr, size);
    cout << "Sorted array after Selection sort:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    arr = NULL;
    return 0;
}
void selectionSort(int *arr, int end)
{
    int pos;
    for (int i = 0; i < end; i++)
    {
        pos = i;
        for (int j = i + 1; j < end; j++)
        {
            if (arr[j] < arr[pos])
            {
                pos = j;
            }
        }
        swap(arr, pos, i);
    }
}
void swap(int *arr, int x, int y)
{
    int temp;
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}