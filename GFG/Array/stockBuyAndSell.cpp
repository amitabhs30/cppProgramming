#include <stdio.h>
#include <iostream>
using namespace std;
int findMaxProfit(int*, int, int);
int findMaxProfitE(int*, int ,int );
int main()
{
    int size, *arr = NULL;
    cout << "Enter the size of array";
    scanf("%d", &size);
    arr = new int[size];
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int res = findMaxProfit(arr, 0, size - 1);
    cout << res << endl;
    delete[] arr;
    arr = NULL;
    return 0;
}

int findMaxProfit(int *arr, int start, int end)   // this is the naive solution through recursion....
{
    if(start>=end)
    {
        return 0;
    }
    int profit=0;
    
    for (int i=start;i<end;i++)
    {
        for (int j=i+1;j<=end;j++)
        {
            if(arr[j]>arr[i])
            {
                int currProfit=arr[j]-arr[i]+findMaxProfit(arr,start,i-1)+findMaxProfit(arr,j+1,end);
                profit=max(profit,currProfit);
            }
        }
    }
    return profit;
}

int findMaxProfitE(int *arr, int start,int end)
{   int profit=0;
    for (int i=1;i<=end;i++)
    {
        if(arr[i-1]<arr[i])
        {
            profit+=arr[i]-arr[i-1];
        }
    }
    return profit;
}