#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int countInv(int *, int ,int);
int countAndMerge(int *, int, int, int);

int main()
{
    int *p, n;
    cout << "Enter the size of array";
    cin >> n;
    p = new int[n];
    cout << "Enter the elements of the array";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int res=countInv(p,0,n-1);
    cout<<res<<endl;
    delete[] p;
    p = NULL;
    return 0;
}
int countInv(int *arr, int start, int end)
{
    int res=0;
    if(start<end)
    {   int mid=(start+end)/2;
        res+=countInv(arr,start,mid);
        res+=countInv(arr,mid+1,end);
        res+=countAndMerge(arr,start,mid,end);
    }
    return res;
}
int countAndMerge(int *arr, int start, int mid,int end)
{
    int n1=mid-start+1,n2=end-mid;
    int right[n1], left[n2];

    for(int i=0;i<n1;i++)
    {
        left[i]=arr[start+i];
    }

    for(int i=0;i<n2;i++)
    {
        right[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=start,res=0;
    while(i<n1&&j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
            res+=(n1-i);
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
    return res;
}
