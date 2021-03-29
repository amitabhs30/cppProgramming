#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

unordered_set<int>smp;
bool canSum(int n, vector<int>nums)
{
    if(smp.find(n)!=smp.end())
    {
        return false;
    }
    if(n==0)
    return true;
    if(n<0)
    return false;
    for(auto e: nums)
    {
        int rem=n-e;
        if(canSum(rem,nums))
            return true;
        smp.insert(n);    
    }
    return false;

}
int main()
{
    vector<int>nums{7,14};

    if(canSum(300,nums))
        cout<<"True";
    else
    {
        cout<<"False";
    }
    return 0;
}