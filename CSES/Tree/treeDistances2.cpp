#include<iostream>
#include<vector>

using namespace std;

vector<int>tree[200005];
int nc[200005];
long long dval[200005];

void nchildCalc(int src,int par)
{
    int nchild=0;
    bool leaf=true;

    for(auto child: tree[src])
    {
        if(child!=par)
        {
            leaf=false;
            nchildCalc(child,src);
            nc[src]+=nc[child]+1;
            dval[src]+=dval[child]+1+nc[child];
        }
    }
    if(leaf)
    {
        nc[src]=0;
        dval[src]=0;
    }
}
void solve(int src,int par,long long parVal,int tn){

    if(src!=1)
    {
        dval[src]=parVal+(tn-2-nc[src])-nc[src];
    }
    for(auto child:tree[src])
    {
        if(par!=child)
        {
            solve(child,src,dval[src],tn);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    nchildCalc(1,0);
    solve(1,0,0,n);
    for(int i=1;i<=n;i++)
    {
        cout<<dval[i]<<" ";
    }
}