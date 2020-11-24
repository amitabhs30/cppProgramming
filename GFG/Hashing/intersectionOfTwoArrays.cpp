#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
void printIntersectionElements(vector<int>, vector<int>);
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
    printIntersectionElements(arr1,arr2);
    return 0;
}
void printIntersectionElements(vector<int>arr1,vector<int>arr2)
{
    unordered_set<int> us1,us2;
    for(auto x : arr1)
    {
        us1.insert(x);
    }
    for(auto x : arr2)
    {
        us1.insert(x);
    } 
    for (auto x :us1 )
    {
        cout<<x<<" ";
    }
}