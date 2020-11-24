#include <stdio.h>
#include <iostream>
using namespace std;
int findMaxProfit(int *, int);
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
    int res = findMaxProfit(arr, size);
    cout << res << endl;
    delete[] arr;
    arr = NULL;
    return 0;
}

int findMaxProfit(int *arr, int size)
{
    int minNo, maxD;
    maxD = arr[1] - arr[0];
    minNo = arr[0];
    for (int i = 1; i < size; i++)
    {
        maxD = (arr[i] - minNo > maxD) ? arr[i] - minNo : maxD;
        minNo = (arr[i] < minNo) ? arr[i] : minNo;
    }
    if (maxD < 0)
        maxD = 0;
    return maxD;
}