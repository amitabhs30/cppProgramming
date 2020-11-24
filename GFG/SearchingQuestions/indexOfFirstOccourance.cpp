#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int res=-1;
int findFirstOccurrence(vector<int>, int, int, int);
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
    sort(arr.begin(), arr.end());
    cout << "Enter the element to find";
    cin >> n;
    int res = findFirstOccurrence(arr, 0, size - 1, n);
    if (res >= 0)
        cout << res << endl;
    else
        cout << "-1" << endl;
    return 0;
}

int findFirstOccurrence(vector<int> arr, int start, int end, int n)//This works in O(logn)time as binary search is implemented.
{
    int mid = (start + end) / 2;
    if (arr[mid] == n)
    {
        if (arr[mid - 1] == arr[mid] && mid > 0)
        {
            findFirstOccurrence(arr, start, mid - 1, n);
        }
        else
        {
            res = mid;
            return res;
        }
    }
    else if (arr[mid] > n)
    {
        findFirstOccurrence(arr, start, mid - 1, n);
    }
    else
    {
        findFirstOccurrence(arr, mid + 1, end, n);
    }
    return res;
}
