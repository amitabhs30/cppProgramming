#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findValue(vector<int>, int);
void BinarySearch(vector<int>, int, int, int);
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
    findValue(arr, n);
    return 0;
}

void findValue(vector<int> arr, int n)
{
    if (arr[0] == n)
    {
        cout<<"Found at position 0";
        return;
    }
    else
    {
        int i = 1;
        while (arr[i] <= n)
        {
            if (arr[i] == n)
            {
               cout<<"found at position"<<i+1<<endl;
               return;
            }
            else
            {
                i = i * 2;
            }
        }
        BinarySearch(arr, i / 2 + 1, i - 1, n);
        return;
    }
}
void BinarySearch(vector<int> arr, int beg, int end, int no)
{
    int mid = (beg + end) / 2;

    if (beg > end)
    {
        cout << "No. not found";
        return;
    }
    else
    {
        if (no == arr[mid])
        {
            cout << "\nNumber found at position " << mid + 1 << " ";
            return;
        }

        else if (no > arr[mid])
            BinarySearch(arr, mid + 1, end, no);
        else
            BinarySearch(arr, beg, mid - 1, no);
    }
}
