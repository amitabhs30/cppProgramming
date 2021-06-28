#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

unordered_set<string>visited;
vector<char>path;
vector<char>pathf;
bool dfs(int i,int j,vector<vector<char> > arr,pair<int,int>end)
{
    string key=to_string(i)+to_string(j);
    visited.insert(key);
    if(i==end.first&&j==end.second)
    {
        return true;
    }
    if(i>0&&arr[i-1][j]=='.'&&visited.find(to_string(i-1)+to_string(j))==visited.end())
    {
        path.push_back('U');
        if(dfs(i-1,j,arr,end))
            return true;
        else
            path.pop_back();
            
    }

    if(i<arr.size()-1&&arr[i+1][j]=='.'&&visited.find(to_string(i+1)+to_string(j))==visited.end())
    {
        path.push_back('D');
        if(dfs(i+1,j,arr,end))
            return true;
        else
            path.pop_back();
        
    }
    if(j>0&&arr[i][j-1]=='.'&&visited.find(to_string(i)+to_string(j-1))==visited.end())
    {
        path.push_back('L');
        if(dfs(i,j-1,arr,end))
            return true;
        else
            path.pop_back();
            
    }
    if(j<arr[i].size()-1&&arr[i][j+1]=='.'&&visited.find(to_string(i)+to_string(j+1))==visited.end())
    {
        path.push_back('R');
        if(dfs(i,j+1,arr,end))
            return true;
        else
            path.pop_back();    
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > arr(n,vector<char>(m));
    pair<int,int>start,end;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='A')
            {   start.first=i;
                start.second=j;
            }
            if(arr[i][j]=='B')
            {   end.first=i;
                end.second=j;
            }
        }
    }
    arr[end.first][end.second]='.';
    if(dfs(start.first,start.second,arr,end))
    {
        cout<<"YES";
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i];
        }
    }
    else
    {
        cout<<"No";
    }
    
    return 0;
}