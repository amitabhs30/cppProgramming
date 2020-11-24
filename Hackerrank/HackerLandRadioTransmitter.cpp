#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int main()
{
    int n,k,e;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int i=0,noOfTransmitter=0;
    while(i<n)
    {
        noOfTransmitter++;
        int loc=arr[i]+k;
        while(i<n&&arr[i]<=loc)i++;
        loc=arr[--i]+k;
        while(i<n&&arr[i]<=loc)i++;
    }
    cout<<noOfTransmitter;
    return 0;
}