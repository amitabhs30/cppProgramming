#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void bfs(unordered_map<int,vector<int> >mp,int root,vector<int>&nodes)
{
    queue<int>q;
    q.push(root);
    //nodes.push_back(root);

    while(!q.empty())
    {
        int s=q.size();
        while(s--)
        {
            int node=q.front();
            nodes.push_back(node);
            q.pop();
            for(int i=0;i<mp[node].size();i++)
            {
                q.push(mp[node][i]);
            }
        }
    }
}

int main(){
    int n,b;
    cin>>n>>b;
    unordered_map<int,vector<int> >mp;

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
    }
    vector<int>nodes;
    bfs(mp,b,nodes);
    vector<int>dp(n+1);
    for(int i=1;i<dp.size();i++)
    {
        dp[i]=1;
    }
    for(int i=nodes.size()-1;i>=0;i--)
    {
            for(int j=0;j<mp[nodes[i]].size();j++)
            {
                dp[nodes[i]]=(dp[nodes[i]]%1000000009*(dp[mp[nodes[i]][j]]+1)%1000000009)%1000000009;
            }
    }
    cout<<dp[b];
    return 0;
}