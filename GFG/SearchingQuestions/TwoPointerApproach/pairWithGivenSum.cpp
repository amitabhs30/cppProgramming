#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int res=-1;
bool findPair(vector<int>, int, int, int);
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
    cout<<"Enter the no. for which the pair is to be found";
    cin>>n;
   bool result = findPair(arr, 0, size - 1,n);
   cout<<result<<endl;
    return 0;
}
bool findPair(vector<int> arr, int start, int end, int n)
{
    while(start<end)
    {
        if(arr[start]+arr[end]==n)
        {
            return true;
        }
        else if(arr[start]+arr[end]>n)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return false;
}
