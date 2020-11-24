#include <stdio.h>
#include <iostream>

using namespace std;
void binarySearch(int[],int,int,int);
void linearSearch(int [],int,int);

int main(){
        int size,no,*arr=NULL,choice;
        cout<<"Enter the size of array";
        scanf("%d",&size);
        arr= new int[size];
        cout<<"Enter the elements of array";
        for(int i=0; i<size; i++)
        {
                cin>>arr[i];
        }
        cout<<"Enter no. to search";
        cin>>no;
        cout<<"1: for Linear Search, 2: for Binary Search\n";
        cin>>choice;
        switch (choice) {
        case 1: linearSearch(arr,size,no);
                break;
        case 2 :binarySearch(arr,no,0,size-1);
                break;
        default:
                cout<<"Enter exact value";
        }
        delete []arr;
        return 0;
}
void linearSearch(int arr[],int size,int no)
{
        if(size==-1)
        {
                cout<<"No. not found";
                return;
        }
        else if(arr[size]==no)
        {
                cout<<"\nNumber Found at position "<<size+1<<" ";
                return;
        }
        else
                size--;
        linearSearch(arr,size,no);
}

void binarySearch(int arr[],int no,int beg,int end)
{
        int mid=(beg+end)/2;

        if(beg>end)
        {
                cout<<"No. not found";
                return;
        }
        else
        {
                if(no==arr[mid])
                {
                        cout<<"\nNumber found at position "<<mid+1<<" ";
                        return;
                }

                else if(no>arr[mid])
                        binarySearch(arr,no,mid+1,end);
                else
                        binarySearch(arr,no,beg,mid-1);
        }

}
