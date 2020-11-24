
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int findSubArray(vector<int>);
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
    int res = findSubArray(arr);
    cout << endl
         << "Longest Consequetive Subsequence "<<res;
    return 0;
}
int findSubArray(vector<int> arr){
    unordered_map<int,int>map;
    int res=0;
    for(int i=0;i<arr.size();i++)
    {
        map[arr[i]]=i;
    }
    for(auto e: arr)
    {
        if(map.find(e-1)!=map.end())
        {
            continue;
        }
        int x=e;
        int count=0;
        while(map.find(x)!=map.end())
        {
            count++;
            x++;
        }
        res=max(res,count);
    }
    return res;
}