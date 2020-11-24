#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
pair<int, int> findSubArray(vector<int>, vector<int>);
int main()
{
    int size, n;
    cout << "Enter the size of array";
    scanf("%d", &size);
    vector<int> arr;
    vector<int> arr1;
    cout << "Enter the elements of array 1";
    for (int i = 0; i < size; i++)
    {
        cin >> n;
        arr.push_back(n);
    }
    cout << "Enter the elements of array 2";
    for (int i = 0; i < size; i++)
    {
        cin >> n;
        arr1.push_back(n);
    }
    pair<int, int> res = findSubArray(arr, arr1);
    cout << endl
         << "Longest span with same sum is from: "
         << res.first << "to " << res.second;
    return 0;
}
pair<int, int> findSubArray(vector<int> arr1, vector<int> arr2)
{
    vector<int> temp;
    unordered_map<int, int> map;
    for (int i = 0; i < arr1.size(); i++)
    {
        temp.push_back(arr1[i] - arr2[i]);
    }
    int preSum = 0, res = 0;
    pair<int, int> result;
    for (int i = 0; i < arr1.size(); i++)
    {
        preSum += temp[i];
        if (preSum == 0)
        {
            if (i > res)
            {
                res = i;
                result.first = 0;
                result.second = i;
            }
        }
        else if (map.find(preSum) != map.end())
        {
            if (i - map[preSum] > res)
            {
                res = i - map[preSum];
                result.first = map[preSum]+1;
                result.second = i;
            }
        }
        else
        {
            map[preSum] = i;
        }
    }
    return result;
}
