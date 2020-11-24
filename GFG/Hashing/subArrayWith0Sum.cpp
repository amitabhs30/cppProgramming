
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
void findSubArray(vector<int>);
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
    
    findSubArray(arr);
    return 0;
}
void findSubArray(vector<int>arr)
{   
    unordered_set<int>us;
    int prefixSum;
    for(auto x: arr)
    {
        prefixSum+=x;
        if(us.find(prefixSum)!=us.end()||prefixSum==0)
        {
           cout<<"One Such pair is present"; 
           return;
        }
        us.insert(prefixSum);
    }
    cout<<"No such pair is present";
}