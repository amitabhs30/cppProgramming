#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void findFrequency(int *, int);
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
    findFrequency(arr,size);
    delete[] arr;
    arr = NULL;
    return 0;
}
void findFrequency(int *arr, int size)
{
    int no,count=1;
    no=arr[0];
    for (int i=1;i<=size;i++)
    {
        //no=arr[i];
        if(arr[i]==no)
        {
            count++;
        }
        else 
        {
            cout<<arr[i-1]<<" "<<count<<endl;
            count=1;
            no=arr[i];
        }
    }
}

