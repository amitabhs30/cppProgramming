#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

unordered_set<int>smp;
vector<int> canSum(int n, vector<int>nums)
{
    if(smp.find(n)!=smp.end())
    {
        vector<int>a;
        return a;
    }
    if(n==0)
        {
            vector<int>a(1,0);
            return a;
        }
    if(n<0)
        {
            vector<int>a;
            return a;
        }
    for(auto e: nums)
    {
        int rem=n-e;
        vector<int>ar=canSum(rem,nums);
        if(ar.size()!=0)
        {
            ar.push_back(e);
            return ar;
        }
        smp.insert(n);
    }
    vector<int>a;
    return a;        
}
int main()
{
    vector<int>nums{5,14};

    vector<int>res=canSum(300,nums);

    if(res.size()==0)
    {
        cout<<"NULL"<<endl;
    }
    else if(res.size()==1&&res[0]==0)
    {
        cout<<"[ ]"<<endl;
    }
    else
    {
        cout<<"[ ";
        for(auto e: res)
        {
            if(e!=0)
            cout<<e<<" ";
        }
        cout<<"]";
    }
    
    return 0;
}