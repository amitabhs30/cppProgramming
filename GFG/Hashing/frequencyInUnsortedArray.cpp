#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
void countDistinctElements(vector<int>);
int main()
{
    int size, n;
    cout << "Enter the size of array";
    scanf("%d", &size);
    vector<int> arr;
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> n;
        arr.push_back(n);
    }
    countDistinctElements(arr);
   
    return 0;

}
void countDistinctElements(vector<int>arr)
{
    unordered_map<int,int>map;
    for(int i=0;i<arr.size();i++)
    {
        map[arr[i]]++;
    }
    for(auto x: map)
    {
        cout<<x.first<<" "<<x.second<<" "<<endl;
    }
}