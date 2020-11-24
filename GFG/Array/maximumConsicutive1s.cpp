#include <stdio.h>
#include <iostream>
using namespace std;
int findMaxCons1(bool *, int, int);
int main()
{
    int size;
    bool *arr;
    cout << "Enter the size of array";
    scanf("%d", &size);
    arr = new bool[size];
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int res = findMaxCons1(arr, 0, size - 1);
    cout << res << endl;
    delete[] arr;
    arr = NULL;
    return 0;
}

int findMaxCons1(bool *arr, int start, int end)
{
    int count=0,res=0;
    for(int i=0;i<=end;i++)
    {
        if(arr[i])
        {
            count++;
            res=max(count,res);
        }
        else
        {
            count=0;
        }
    }
    return res;
}