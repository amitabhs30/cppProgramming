#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printUnionElements(vector<int>, vector<int>);
int main()
{
    int size1,size2, n;
    cout << "Enter the size of 1 array";
    scanf("%d", &size1);
    cout <<"Enter the size of 2 array";
    scanf("%d",&size2);
    vector<int> arr1;
    vector<int>arr2;
    cout << "Enter the elements of array1";
    for (int i = 0; i < size1; i++)
    {
        cin >> n;
        arr1.push_back(n);
    }
    cout<<"Enter the elements of array2";
    for (int i = 0; i < size2; i++)
    {
        cin >> n;
        arr2.push_back(n);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(),arr2.end());
    printUnionElements(arr1,arr2);
    return 0;
}
void printUnionElements(vector<int>arr1,vector<int>arr2)
{
    int n=arr1.size()-1;
    int m=arr2.size()-1;
    int s=0,t=0;

    while(s<arr1.size()-1&&t<arr2.size()-1)
    {
        if(arr1[s]==arr1[s-1]&&s>0)
        {
            s++;
            continue;
        }
        if(arr2[t]==arr2[t-1]&&t>0)
        {
            t++;
            continue;
        }
        if(arr1[s]>arr2[t])
        {
            cout<<arr2[t]<<" ";
        }
        else if(arr1[s]<arr2[t])
        {
            cout<<arr1[s]<<" ";
        }
        else
        {
            cout<<arr1[s]<<" ";
            s++;
            t++;
        }
    }
    while(s<arr1.size()-1)
    {
        if(s>0&&arr1[s]!=arr1[s-1])
        {
            cout<<arr1[s]<<endl;
        }
        s++;
    }
    while(t<arr2.size()-1)
    {
        if(t>0&&arr2[t]!=arr2[t-1])
        {
            cout<<arr2[t]<<endl;
        }
        t++;
    }

}