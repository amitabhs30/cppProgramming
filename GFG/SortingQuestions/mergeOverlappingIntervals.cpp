#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct range
{
    int start;
    int end;
};

bool Mysort(range x,range y){
    return(x.start<y.start);
}
void mergeOverlappingRange(vector<range>);

int main()
{
    int n,left,right;
    cout<<"Enter the size of array";
    cin>>n;
    vector<range>arr;
    cout<<"Enter the pairs like this: x,y";
    for(int i=0;i<n;i++)
    {
        range r;
        scanf("%d,%d",&r.start,&r.end);
        arr.push_back(r);
    }
    mergeOverlappingRange(arr);
    
    return 0;
}

void mergeOverlappingRange(vector<range>arr)
{
    sort(arr.begin(),arr.end(),Mysort);

    int res=0;
    for (int i=1;i<arr.size();i++)
    {
        if(arr[res].end>=arr[i].start)
        {
            arr[res].start=min(arr[res].start,arr[i].start);
            arr[res].end=max(arr[res].end,arr[i].end);
        }
        else
        {
            res++;
            arr[res]=arr[i];
        }
    }
    for(int i=0;i<=res;i++)
    {
        cout<<arr[i].start<<","<<arr[i].end<<" ";
    }
}