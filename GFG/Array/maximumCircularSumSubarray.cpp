#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int findMaxSumInC(vector<int>, int);
int findMaxSumInN(vector<int>,int);
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
    int res=findMaxSumInC(arr,size);
    cout<<res<<endl;
    return 0;
}
// int findMaxSum(vector<int>arr,int end)   //Naive O(n^2)
// {   int currSum,res=0,curr;
//     for(int i=0;i<end;i++)  
//     {   curr=0;
//         currSum=arr[i];
//         for(int j=0;j<end;j++)
//         {   int index=(i+j)%end;
//             curr+=arr[index];
//             currSum=max(currSum,res);
//         }
//         res=max(currSum,res); 
//     }
//     return res;
// }

int findMaxSumInC(vector<int>arr, int end)
{
    int maxSumInN=findMaxSumInN(arr,end);

    if(maxSumInN<0)
    {
        return maxSumInN;
    }
    int sum=0;
    for(int i=0;i<end;i++)
    {
        sum+=arr[i];
        arr[i]=-arr[i];
    }
    int minNormal=findMaxSumInN(arr,end);
    int maxSumInC=sum+minNormal;

    return max(maxSumInN,maxSumInC);
}

int findMaxSumInN(vector<int> arr, int end)
{
    int curr=arr[0],maxCurr=arr[0];

    for(int i=1;i<end;i++)
    {
        curr=max(arr[i],curr+arr[i]);
        maxCurr=max(curr,maxCurr);
    }
    return maxCurr;
}