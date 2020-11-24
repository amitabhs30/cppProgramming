#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>arr;
int findKthSmallestElement( int, int, int);
int partition(int, int);

int main()
{
    int n, e;
    cout << "Enter the size of array";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        arr.push_back(e);
    }
    cout << "Enter the value of K";
    cin >> e;
    int res = findKthSmallestElement( 0, n - 1, e);
    cout << res;
    return 0;
}

int findKthSmallestElement( int start, int end, int k)
{
    while (start <= end)
    {
        int p = partition(start, end);
        if (p == k - 1)
        {
            return arr[p];
        }
        else if (p > k - 1)
        {
            end = p - 1;
        }
        else
        {
            start = p + 1;
        }
    }
    return -1;
}

int partition( int start, int end) // this is nothing but the lomuto partition of the quicksort
{
    int pivotValue = arr[end];

    int j = start;

    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivotValue)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        }
    }
    int temp = arr[j];
    arr[j] = arr[end];
    arr[end] = temp;

    return j;
}
