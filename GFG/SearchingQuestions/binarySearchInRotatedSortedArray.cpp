#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void updatedBinarySearch(vector<int>, int, int, int);
int main()
{
    int size, n;
    cout << "Enter the size of array";
    scanf("%d", &size);
    vector<int> arr;
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> n;
        arr.push_back(n);
    }
//    sort(arr.begin(), arr.end());
    cout << "Enter the element to find";
    cin >> n;
    updatedBinarySearch(arr, 0, size - 1, n);
    return 0;
}
void updatedBinarySearch(vector<int> arr, int start, int end, int n)
{
    while (start <= end)
    {   int mid = (start + end) / 2;
        if (arr[mid] == n)
        {
            cout << "Found at position:" << mid + 1;
            return;
        }

        else if (arr[mid] > arr[start])
        {
            if(n>=arr[start]&&n<arr[mid])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        else if (arr[mid]<arr[start])
        {
            if(n>arr[mid]&&n<=arr[end])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    }
    if(start>end)
    {
        cout<<"Not found in the array";
    }
    return;
}
