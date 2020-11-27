//This is the quick sort algorithm by Hoare's Partition.


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > arr;

int partitionHoare(int, int, int);

void quickSort(int, int, int);
int res = -1;
int main()
{
    int n, e, size;
    cout << "Enter the size of array";
    cin >> size;
    cout << "Enter the elements of the array";
    for (int i = 0; i < size; i++)
    {
        cin >> e;
        arr.push_back(make_pair(e, i));
    }
    cout << "Enter the value to search";
    cin >> n;
    quickSort(0, size - 1, n);
    if (res == -1)
        cout << "Not Present";
    else
        cout << res << endl;
    return 0;
}

void quickSort(int start, int end, int n)
{
    if (start >= end)
    {
        return;
    }
    int pivotValue = arr[start].first;
    if (arr[start].first == n)
    {
        res = arr[start].second;
        return;
    }
    int pivotIndex = partitionHoare(start, end, pivotValue);

    if (n < pivotValue)
    {
        quickSort(start, pivotIndex, n);
    }
    else
    {
        quickSort(pivotIndex + 1, end, n);
    }
}

int partitionHoare(int start, int end, int pivotValue)
{
    int i = start - 1, j = end + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i].first < pivotValue);

        do
        {
            j--;
        } while (arr[j].first > pivotValue);

        if (i >= j)
        {
            return j;
        }

        pair<int, int> temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
