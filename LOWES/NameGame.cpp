//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

#define mod 
#define lli long long int


using namespace std;

unordered_map<int,vector<int> >graph;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>visited(n,0);
        vector<string>st(n);
        vector<bitset<26> >uniq(n,bitset<26>());
        unordered_map<int,vector<int> >graph;
        for(int i=0;i<n;i++)
        {
            cin>>st[i];
        }
        for(int i=0;i<n;i++)
        {
            for(char c: st[i])
            {
                uniq[i].set(c-'A');
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                visited[i]=1;
                graph[i].push_back(i);
                for(int j=1;j<n;j++)
                {
                    if(!visited[j])
                    {
                        bitset<26>tmp=uniq[i]^uniq[j];
                        if(tmp.count()<=2)
                        {
                            visited[j]=1;
                            graph[i].push_back(j);
                        }
                    }
                }
            }
        }
        int ans=0;
        for(auto e: graph)
        {
            ans=max(ans,int(e.second.size()));
        }
        cout<<ans<<" "<<graph.size()<<endl;
    }
}