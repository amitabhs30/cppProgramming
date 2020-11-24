
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
struct data
{
    vector<int> indexes;
};
void findSubArray(vector<int>, int);
int main()
{
    int size, n;
    scanf("%d", &size);
    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
        cin >> n;
        arr.push_back(n);
    }
    cin >> n;
    findSubArray(arr, n);
    return 0;
}
void findSubArray(vector<int> arr, int sum)
{
    unordered_map<int, int> map;
    unordered_map<int, data> mapIndex;
    int prefixSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];
        if (prefixSum == sum)
        {
            
              cout << "{ ";
                for (int j = 0; j <= i; j++)
                {
                    cout << arr[j] << " ";
                }
                cout << "}" << endl;
        
        }
        if (map.find(prefixSum) != map.end())
        {
            if (mapIndex.find(prefixSum) != mapIndex.end())
            {
                mapIndex[prefixSum].indexes.push_back(i);
            }
            else
            {
                mapIndex[prefixSum].indexes.push_back(i);
                mapIndex[prefixSum].indexes.push_back(map[prefixSum]);
            }
        }
        if (map.find(prefixSum - sum) != map.end())
        {
            if (mapIndex.find(prefixSum-sum) != mapIndex.end())
            {
                for (int z=0;z<mapIndex[prefixSum-sum].indexes.size();z++)
                {
                    cout << "{ ";
                    for (int j = mapIndex[prefixSum-sum].indexes[z] + 1; j <= i; j++)
                    {
                        cout << arr[j] << " ";
                    }
                    cout << "}" << endl;
                }
            }
            else
            {
            cout << "{ ";
            for (int j = map[prefixSum-sum] + 1; j <= i; j++)
            {
                cout << arr[j] << " ";
            }
            cout << "}" << endl;
            }
        }
        else
        {
            map[prefixSum] = i;
        }
    }
}
