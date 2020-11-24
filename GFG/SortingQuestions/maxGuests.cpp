#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void MaxGuestsThatCanBeMet(vector<int>, vector<int>);
int main()
{
    int size1,size2, n;
    cout << "Enter the number of arrivals";
    scanf("%d", &size1);
    cout <<"Enter the number of departures";
    scanf("%d",&size2);
    vector<int> arr1;
    vector<int>arr2;
    cout << "Enter the time of arrivals";
    for (int i = 0; i < size1; i++)
    {
        cin >> n;
        arr1.push_back(n);
    }
    cout<<"Enter the time of departures";
    for (int i = 0; i < size2; i++)
    {
        cin >> n;
        arr2.push_back(n);
    }
    MaxGuestsThatCanBeMet(arr1,arr2);
    return 0;
}
void MaxGuestsThatCanBeMet(vector<int> arrivals,vector<int> departures)
{
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(),departures.end());

    int i=1,j=0,curr=1,res=1;

    while(i<arrivals.size()&&j<departures.size())
    {
        if(arrivals[i]<=departures[j])
        {
            curr++;
            i++;
        }
        else
        {
            j++;
            curr--;
        }
        res=max(res,curr);
    }
    cout<<res<<" Guests can be met at one time";
}