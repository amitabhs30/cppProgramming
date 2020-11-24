
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int findPair(vector<unsigned long long int>, int, long long int);
int main()
{
    int size;
    unsigned long long int n;
    long long int k;
    scanf("%d", &size);
    cin>>k;
    vector<unsigned long long int>arr;
    for(int i=0;i<size;i++)
    {
        cin>>n;
        arr.push_back(n);
    }
    int res=findPair(arr,size-1,k);
    cout<<res<<endl;
    return 0;
}
int findPair(vector<unsigned long long int>arr, int end, long long int k)
{

    sort(arr.begin(),arr.end());

    int i=0,j=1;
    int count=0;

    while(j<=end)
    {
        if(arr[j]-arr[i]==k)
        {
            count++;
            j++;
        }
        else if(arr[j]-arr[i]>k)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return count;

}
