
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
void findPair(vector<int>,int);
int main()
{
    int size,n;
    cout << "Enter the size of array";
    scanf("%d", &size);
    vector<int>arr;
    cout << "Enter the elements of array";
    for(int i=0;i<size;i++)
    {
        cin>>n;
        arr.push_back(n);
    }
    cout<<"Enter Sum";
    int k;
    cin>>k;
    findPair(arr,k);
    return 0;
}
void findPair(vector<int>arr, int k)
{
    unordered_set<int>us;
    for(auto x:arr)
    {
        int val=k-x;
        if(us.find(val)!=us.end())
        {
            cout<<x<<" "<<val;
            return;
        }
        us.insert(x);
    }
    cout<<"No Pair Found!";
}
