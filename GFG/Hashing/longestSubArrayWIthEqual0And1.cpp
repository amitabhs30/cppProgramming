
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int findSubArray(vector<bool>);
int main()
{
    int size, n;
    cout << "Enter the size of array";
    scanf("%d", &size);
    vector<bool> arr;
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> n;
        arr.push_back(n);
    }
    int res = findSubArray(arr);
    cout << endl
         << "Longest Subarray with Equal 0 and 1:"
         << " ";
        cout << res << " ";
    return 0;
}
int findSubArray(vector<bool> arr)
{
    unordered_map<int,int>map;

    int prefixSum=0;
    int res=INT32_MIN;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i])
        prefixSum++;
        else
        prefixSum--;

        if(prefixSum==0)
        {
            res=max(res,i+1);
        }
        else if(map.find(prefixSum)!=map.end())
        {
            res=max(res,i-map[prefixSum]);
        }
        else
        {
            map[prefixSum]=i;
        }
    }
    if(res==INT32_MIN)
    {
        return 0;
    }
    else return res;
}