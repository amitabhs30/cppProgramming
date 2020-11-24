#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int res=-1;
int findPeakElement(vector<int>, int, int);
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
   int result = findPeakElement(arr, 0, size - 1);
   cout<<"Peak Element is "<<result<<endl;
    return 0;
}
int findPeakElement(vector<int> arr, int start, int end)
{
    while (start<=end)
    {
        
        int mid=(start+end)/2;
        if((mid==0||arr[mid]>arr[mid-1])&&
        (mid==arr.size()-1||arr[mid]>arr[mid+1]))
        {
            return arr[mid];
        }
        else if(arr[mid]>arr[mid-1])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        } 
    }
    return -1;
}
