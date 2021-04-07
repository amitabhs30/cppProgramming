#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;


class Solution {
public:
    unordered_map<string,int>mp;
    int N,M;

    int uniquePath(int m,int n,vector<vector<int> >& obstacleGrid)
    {
        string k=to_string(m)+','+to_string(n);
        if(mp.find(k)!=mp.end())
            return mp.at(k);  
        if(m==1&&n==1)
            return 1;
        if(m==0||n==0)
            return 0;
        if(obstacleGrid[M-m][N-n])
        {
            mp.insert(make_pair(k,0));
            return 0;
        }  
        mp.insert(make_pair(k,uniquePath(m-1,n,obstacleGrid)+uniquePath(m,n-1,obstacleGrid)));
        return mp.at(k);
    }

     int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        N=n;
        M=m;
        return(uniquePath(m,n,obstacleGrid));
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

    //startup();
    Solution s;
    vector<vector<int> >a(2,vector<int>(2));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>a[i][j];
        }
    }
    int res=s.uniquePathsWithObstacles(a);
    cout<<res<<endl;
    return 0;
}

