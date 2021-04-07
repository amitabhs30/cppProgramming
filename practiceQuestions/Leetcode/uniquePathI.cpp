#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;


class Solution {
public:
    unordered_map<string,int>mp;
    int uniquePaths(int m, int n) {
        string k=to_string(m)+','+to_string(n);
        if(mp.find(k)!=mp.end())
            return mp.at(k);
        if(m==1&&n==1)
            return 1;
        if(m==0||n==0)
            return 0;
        // return (uniquePaths(m-1,n)+uniquePaths(m,n-1));        
        mp.insert(make_pair(k,uniquePaths(m-1,n)+uniquePaths(m,n-1)));
        return mp.at(k);
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


int main(){

    startup();
    Solution s;
    int n,m;
    cin>>m>>n;
    int res=s.uniquePaths(m,n);
    cout<<res<<endl;
    return 0;
}

