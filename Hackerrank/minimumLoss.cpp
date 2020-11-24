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
    map<long,int>m;
    for(int i=0;i<arr.size();i++)
    {
        m[arr[i]]=i;
    }
    sort(arr.begin(),arr.end());
    long minLoss=INT32_MAX;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i+1]-arr[i]<minLoss)
        {
            int first=m[arr[i]];
            int second=m[arr[i+1]];
            if(second<first)
            {
                minLoss=min(minLoss,arr[i+1]-arr[i]);
            }
        }
    }
    return minLoss;

}

