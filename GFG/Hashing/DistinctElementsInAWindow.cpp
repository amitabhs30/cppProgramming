
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
void findDisElements(vector<int>, int);
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
    cout << "Enter size of window";
    cin >> n;
    findDisElements(arr, n);
    return 0;
}
void findDisElements(vector<int> arr, int k)
{
    unordered_map<int,int>map;
    for (int i = 0; i < k; i++)
    {
        map[arr[i]]++;
    }
    cout<<endl<<map.size()<<" ";
    
    for(int i=k;i<arr.size();i++)
    {
        int fe=arr[i-k];
        int le=arr[i];

        map[fe]--;
        map[le]++;
        if(map[fe]==0)
        {
            map.erase(fe);
        }
        cout<<map.size()<<" ";
    }
}