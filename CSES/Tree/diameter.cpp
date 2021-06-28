#include<iostream>
#include<vector>
#include<algorithm>
//#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;


vector<int>tree[200005];
int diameter[200005];
int downpath[200005];

void fdownpath(int src,int p)
{
    int best_child_down_path=0;
    bool leaf=1;
    for(int child:tree[src])
    {
        if(p!=child)
        {
            leaf=0;
            fdownpath(child,src);
            best_child_down_path=max(best_child_down_path,downpath[child]);
        }
    }
    if(leaf)downpath[src]=0;
    else downpath[src]=best_child_down_path+1;
}

void solve(int src,int parent){
    int ans=0;
    vector<int>childDownPaths;
    for(int child:tree[src])
    {
        if(child!=parent)
        {
            solve(child,src);
            childDownPaths.pb(downpath[child]);
            ans=max(ans,diameter[child]);
        }
    }
    int childCount=childDownPaths.size();
    sort(all(childDownPaths));
    if(childCount==0)diameter[src]=0;
    else if(childCount==1)diameter[src]=1+childDownPaths[childCount-1];
    else diameter[src]=2+childDownPaths[childCount-1]+childDownPaths[childCount-2];
    diameter[src]=max(ans,diameter[src]);
}

int main(){
    fast_io;
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    fdownpath(1,0);
    solve(1,0);
    cout<<diameter[1];
    return 0;
}