#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int partition(int *, int, int, int);

void quickSort(int *, int, int);
void swap(int *, int, int);

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
    quickSort(p, 0, n - 1);
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    // delete [] p;
    // p=NULL;
    return 0;
}

void quickSort(int *arr, int start, int end)
{
    if (start>=end)
    {
        return;
    }
    int pivotValue=arr[end];

    int pivotIndex=partition(arr,start,end,pivotValue);

    quickSort(arr, start, pivotIndex-1);
    quickSort(arr, pivotIndex+1, end);

}

int partition(int *arr, int start, int end , int pivotValue)
{
    int pivotIndex,i=start,j=start;

    for(i=start;i<end;i++)
    {
        if(arr[i]<=pivotValue)
        {
            swap(arr,i,j);
            j++;
        }
    }
    swap(arr,end,j);
    return j;


    return pivotIndex;

}
void swap(int *p, int x, int y)
{
    int temp = p[x];
    p[x] = p[y];
    p[y] = temp;
}
