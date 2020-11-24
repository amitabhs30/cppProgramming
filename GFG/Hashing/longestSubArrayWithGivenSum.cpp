
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
pair<int, int> findSubArray(vector<int>, int);
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
    cout << "Enter the Sum";
    cin >> n;
    pair<int, int> res = findSubArray(arr, n);
    cout << endl
         << "Longest Subarray with given sum:"
         << " ";
    for (int i = res.first; i <= res.second; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
pair<int, int> findSubArray(vector<int> arr, int sum)// using unordered map, takes only O(n) time complexity and O(n) auxilary space.
{
    unordered_map<int, int> map;
    int preSum = 0;
    int res = INT32_MIN;
    pair<int, int> x;
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        if (preSum == sum)
        {
            x.first = 0;
            x.second = i;
            return x;
        }
        if (map.find(preSum) == map.end())
        {
            map[preSum]=i;
        }
        if (map.find(preSum - sum) != map.end())
        {
            if (res < i - map[preSum - sum])
            {
                res = i - map[preSum-sum];
                x.first = map[preSum - sum]+1;
                x.second = i;
            }
        }
    }
    return x;
}