


#include <stdio.h>
#include <iostream>
using namespace std;
void heapSort(int *,int,int);
void heapify(int *,int ,int);
void swap(int *,int, int);
int main(){
        int size,no,*arr=NULL;
        cout<<"Enter the size of array";
        scanf("%d",&size);
        arr= new int[size];
        cout<<"Enter the elements of array";
                for(int i=0; i<size; i++)
        {
                cin>>arr[i];
        }
        heapSort(arr,0,size-1);
        cout<<"Sorted array after heap sort:"<<" ";
        for (int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        delete []arr;
        arr=NULL;
        return 0;
}
void heapSort(int *arr,int start,int end)
{
    for(int i=end/2;i>=start;i--) //O(n)
    {
        heapify(arr,i,end); //O(1)
    }
    for(int i=end;i>=start;i--)//O(n)
    {
        swap(arr,start,i);//O(1)
        heapify(arr,start,i-1);//O(1)
    }
}
void heapify(int *arr,int start,int end)
{
    int lchild=start*2+1;
    int rchild=start*2+2;
    int largest=start;
    if(lchild<=end&&arr[lchild]>arr[largest])
    {
        largest=lchild;
    }
    if(rchild<=end&&arr[rchild]>arr[largest])
    {
        largest=rchild;
    }
    if(largest!=start)
    {
        swap(arr,largest,start);
        heapify(arr,largest,end);
    }
}
void swap(int * arr,int x,int y)
{
    int temp=arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
}
