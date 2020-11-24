//This is the quick sort algorithm by Hoare's Partition.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>arr;

int partitionHoare(int, int, int);

void quickSort(int, int);


int main()
{
    int n, e;
    cout << "Enter the size of array";
    cin >> n;
    cout << "Enter the elements of the array";
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        arr.push_back(e);
    }
    quickSort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
  
    return 0;
}

void quickSort(int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivotValue = arr[start];

    int pivotIndex = partitionHoare(start, end, pivotValue);

    quickSort(start, pivotIndex);
    quickSort(pivotIndex + 1, end);
}

int partitionHoare(int start, int end, int pivotValue)
{
    int i = start - 1, j = end + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivotValue);

        do
        {
            j--;
        } while (arr[j] > pivotValue);
        
        if (i >= j)
        {
            return j;
        }
        
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        
        
    }
    
}

