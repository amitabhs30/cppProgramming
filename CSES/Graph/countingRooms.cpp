#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void dfs(vector<vector<pair<char,int> > >&mp,int id,vector<pair<pair<int,int>,bool> >&arr)
{
    arr[id].second=true;
    int x=arr[id].first.first;
    int y=arr[id].first.second;
        if(x>0&&mp[x-1][y].first=='.'&&(!arr[mp[x-1][y].second].second))
        {
            dfs(mp,mp[x-1][y].second,arr);
        }
        if(x<mp.size()-1&&mp[x+1][y].first=='.'&&(!arr[mp[x+1][y].second].second))
        {
            dfs(mp,mp[x+1][y].second,arr);
        }
        if(y>0&&mp[x][y-1].first=='.'&&(!arr[mp[x][y-1].second].second))
        {
            dfs(mp,mp[x][y-1].second,arr);
        }
        if(y<mp[0].size()-1&&mp[x][y+1].first=='.'&&(!arr[mp[x][y+1].second].second))
        {
            dfs(mp,mp[x][y+1].second,arr);
        }   
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<char,int> > >mp(n,vector<pair<char,int> >(m));
    vector<pair<pair<int,int>,bool> >arr;
    int id=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mp[i][j].first;
            if(mp[i][j].first=='.')
            {
                pair<int,int>p=make_pair(i,j);
                arr.push_back(make_pair(p,false));
                mp[i][j].second=id++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i].second==false)
        {
            dfs(mp,i,arr);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}