#include <stdio.h>
#include <iostream>
using namespace std;
int maximumSumSubarray(int *, int, int);
int maximumSumSubarrayE(int *, int, int);
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
    int res = maximumSumSubarray(arr, 0, size - 1);
    cout << res << endl;
    delete[] arr;
    arr = NULL;
    return 0;
}
int maximumSumSubarray(int *arr, int start, int end) //Naive solution O(n^2)
{
    int res = arr[0];
    for (int i = 0; i <= end; i++)
    {
        int curr = 0;
        for (int j = i; j <= end; j++)
        {
            curr = curr + arr[j];
            res = max(res, curr);
        }
    }
    return res;
}

int maximumSumSubarrayE(int *arr, int start, int end) //Efficient O(n)
{
    int maximumS = arr[0];
    int res = arr[0];
    for (int i = 1; i <= end; i++)
    {
        maximumS = max(maximumS + arr[i], arr[i]);
        res = max(res, maximumS);
    }
    return res;
}
