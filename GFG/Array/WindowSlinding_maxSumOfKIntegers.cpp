
#include <iostream>
#include <vector>
using namespace std;
int findMaxSumOfK(vector<int>, int, int);
int main()
{
    int size,n;
    cout << "Enter the size of array";
    scanf("%d", &size);
    vector<int>arr;
    cout << "Enter the elements of array";
    for(int i=0;i<size;i++)
    {
        cin>>n;
        arr.push_back(n);
    }
    cout<<"Enter K";
    int k;
    cin>>k;
    int res=findMaxSumOfK(arr,size,k);
    cout<<res<<endl;
    return 0;
}
int findMaxSumOfK(vector<int>arr, int end, int k)
{   int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    int currSum=sum;
    for(int i=k;i<end;i++)
    {
        currSum+=arr[i]-arr[i-k];
        sum=max(currSum,sum);
    }
    return sum;
}