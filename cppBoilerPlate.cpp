//#include<bits/stdc++.h>
#include "/Users/amitabh/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
#define deb(x) cout << #x << "=" << x << endl
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef unordered_set<int, int> usii;
typedef unordered_map<int, int> umii;
typedef map<int, int> mii;

int mpow(int base, int exp);

struct node{
      int id;
      vector<node*>children;
      node* parent;
      int reachableNodes;
      int dval; 
      bool visited=false;

      void addchild(node *j)
      {
        children.push_back(j);
      }
    };

void findDval(vector<node*>&tree,int node)
{ 
  int sum,rnodes;
  for(auto e: tree[node]->children)
  {
    findDval(tree,e->id);
  }
  if(tree[node]->children.size()==0)
  {
    tree[node]->dval=0;
    tree[node]->reachableNodes=0;
  }
  else
  {
    sum=0;
    rnodes=0;
    for(auto e : tree[node]->children)
    {
      sum+=e->dval;
      sum+=e->reachableNodes;
      rnodes+=e->reachableNodes;

    }
    tree[node]->dval=tree[node]->children.size()+sum;
    tree[node]->reachableNodes=rnodes+tree[node]->children.size();
  }
}

int findNDval(vector<node*>&tree,node* parent,node* node){
    node->visited=true;
    int ndval=0;
    ndval=parent->dval+(tree.size()-2)-(2*node->children.size());
    node->dval=ndval;

    return ndval;
}

void findResult(vector<int>&result,vector<node*>&tree,node* parent)
{
  parent->visited=true;
  for(auto e: parent->children)
  {
    if(!(e->visited))
    result[e->id]=findNDval(tree,parent,e);
    findResult(result,tree,e);
  }
}

void solve()
{
  int n;
  vector<vector<int> >edges(1,vector<int>(2));
  cin>>n;
  unordered_map<int,node*>map;
  vector<node *>tree(n);

  for(int i=0;i<n;i++)
  {
    tree[i]=new node();
    map.insert(make_pair(i,tree[i]));
    tree[i]->id=i;
  }
  for(int i=0;i<1;i++)
  {
    for(int j=0;j<2;j++)
    {
      cin>>edges[i][j];
    }
  }

  for(int i=0;i<edges.size();i++)
  {
      map.at(edges[i][0])->addchild(map.at(edges[i][1]));
      //map.at(edges[i][1])->addchild(map.at(edges[i][0]));
      map.at(edges[i][1])->parent=map.at(edges[i][0]);
  }
  findDval(tree,0);
  vector<int>result(n,0);
  result[0]=map.at(0)->dval;
  
  findResult(result,tree,map.at(0));


  for(int i=0;i<n;i++)
  {
    cout<<result[i]<<" ";
  }

}

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

int32_t main()
{
  startup();
  //w(t)
  //{
  solve();
  //}
  return 0;
}

int mpow(int base, int exp)
{

  base %= mod;
  int result = 1;
  while (exp > 0)
  {
    if (exp & 1)
      result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
