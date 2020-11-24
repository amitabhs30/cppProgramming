#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
long solve(vector<long>);
int main()
{
    int size;
    long n;
    vector<long>arr;
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        cin >>n;
        arr.push_back(n);
    }
    long res = solve(arr);
    cout << res << endl;
    return 0;
}

long solve(vector<long>arr)
{
    sort(arr.begin(),arr.end());
    int diff;
    long res= INT32_MAX;
    for(int i=1;i<arr.size();i++)
    {
        diff=arr[i]-arr[i-1];
        if(diff<0)
        {
            diff=diff*(-1);
        }
        res=min(res,(long)diff);
    }
    return res;
}

