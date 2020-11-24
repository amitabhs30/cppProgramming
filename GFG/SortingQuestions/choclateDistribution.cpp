#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>arr;
int findMinDiff(int, int, int);


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
    cout << "Enter the no. of children";
    cin >> e;
    int res = findMinDiff( 0, n - 1, e);
    cout << res;
    return 0;
}
int findMinDiff(int start, int end, int m)
{
    if(m>end+1)
    {
        return -1;
    }
    sort(arr.begin(),arr.end());
    int res=arr[m-1]-arr[0];
    for(int i=1;(i+m-1)<=end;i++)
    {
        res=min(res,arr[m+i-1]-arr[i]);
    }
    return res;
}