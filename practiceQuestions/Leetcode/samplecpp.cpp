#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    unordered_map<int,int>dp;
    int findSol(vector<int>&cost,int n){
        if(n>=cost.size())
        return 0;
        if(dp.find(n)!=dp.end())
        return dp[n];
        dp[n]=cost[n]+min(findSol(cost,n+1),findSol(cost,n+2));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        findSol(cost,0);
        return min(dp[0],dp[1]);
    }
};

void startup()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{

    //startup();
    Solution s;
    int n;
    cin>>n;
    vector<int>x(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    cout<<s.minCostClimbingStairs(x);
    return 0;
}
