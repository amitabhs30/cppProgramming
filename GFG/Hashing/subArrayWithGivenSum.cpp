
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
void findSubArray(vector<int>, int);
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
    cout<<"Enter the Sum";
    cin>>n;
    findSubArray(arr,n);
    return 0;
}
void findSubArray(vector<int>arr, int sum)
{   
    unordered_set<int>us;
    int prefixSum=0;

    for(auto x: arr)
    {   prefixSum+=x;
        if(prefixSum==sum)
        {
            cout<<"Pair found!"<<x<<endl;
            return;
        }
        else if(us.find(prefixSum-sum)!=us.end())
        {
            cout<<"Pair found!"<<x<<endl;
            return;
        }
        us.insert(prefixSum);
    }
    
    cout<<"No such pair is present";
}