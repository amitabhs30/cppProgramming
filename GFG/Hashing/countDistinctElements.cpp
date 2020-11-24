#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int countDistinctElements(vector<int>);
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
    int res = countDistinctElements(arr);
    cout << res <<" Distinct elements are present."<< endl;    
    return 0;

}
int countDistinctElements(vector<int>arr)
{
    unordered_set<int>us;
    for(int x: arr)
    {
        us.insert(x);
    }
    return us.size();
}