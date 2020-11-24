#include <stdio.h>
#include <iostream>
using namespace std;
void mergeSort(int *, int *, int, int);
void merge(int *, int *, int, int, int);
int main()
{
    int size, *arr = NULL, *temp = NULL;
    cout << "Enter the size of array";
    scanf("%d", &size);
    arr = new int[size];
    temp = new int[size];
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, temp, 0, size-1);
    cout << "Sorted array after Merge sort:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    arr = NULL;
    return 0;
}

void mergeSort(int *arr, int *temp, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, temp, start, mid);
    mergeSort(arr, temp, mid+1, end);

    merge(arr, temp, start, mid+1, end);
}

void merge(int *arr, int *temp, int start, int mid, int end)
{
    int Lend = mid - 1, tempPos = start,size= end-start+1;

    while ((start <= Lend) && (mid <= end))
    {
        if (arr[start] < arr[mid])
        {
            temp[tempPos] = arr[start];
            start++;
            tempPos++;
        }
        else
        {
            {
                temp[tempPos] = arr[mid];
                mid++;
                tempPos++;
            }
        }
    }
    while (start <= Lend)
    {
        temp[tempPos] = arr[start];
        start++;
        tempPos++;
    }
    while (mid <= end)
    {
        temp[tempPos] = arr[mid];
        mid++;
        tempPos++;
    }
    for (int i=0;i<size;i++)
    {
        arr[end]=temp[end];
        end--;
    }
}
