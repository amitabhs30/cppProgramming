#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> tree[200005];
int downL[200005];
int maxD[200005];

void findDL(int src, int par)
{
    int maxh = 0;
    bool leaf = true;
    for (auto child : tree[src])
    {
        if (child != par)
        {
            leaf = false;
            findDL(child, src);
            maxh = max(1 + downL[child], maxh);
        }
    }
    if (leaf)
    {
        downL[src] = 0;
    }
    else
    {
        downL[src] = maxh;
    }
}
bool sor(const pair<int,int>a,const pair<int,int>b)
{
    return a.second>b.second?true:false;
}
void solve(int src, int par, int pval)
{

    int maxchildD;
    vector<pair<int,int> > childH;
    for (auto child : tree[src])
    {
        if (par != child)
        {
            childH.push_back(make_pair(child,downL[child]));
        }
    }
    sort(childH.begin(), childH.end(),sor);
    maxD[src]=pval+1;
    if (childH.size() == 1)
    {
        maxD[src] = max(pval+1, childH[0].second+1);
        solve(childH[0].first, src, pval+1);
    }
    else if(childH.size()!=0)
        for (auto child : tree[src])
        {   
            maxD[src] = max(pval+1, childH[0].second+1);
            if (child != par)
            {
                int pv = childH[0].second+1;
                if (childH[0].second== downL[child])
                {
                    pv = childH[1].second+1;
                }
                pv = max(pv, pval + 1);
                solve(child, src, pv);
            }
        }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    findDL(1, 0);
    solve(1, 0, -1);
    for (int i = 1; i <= n; i++)
    {
        cout << maxD[i] << " ";
    }
    return 0;
}