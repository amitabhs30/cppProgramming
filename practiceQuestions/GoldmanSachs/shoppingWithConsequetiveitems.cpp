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

void solve()
{
  int i, j, k, p, n, x, flag = 0;

  cin >> n >> x;
  vector<int> cost(n);

  fo(i, n)
  {
    cin >> cost[i];
  }

  queue<int> q;

  int maxi = INT32_MIN;
  int sum = 0;

  i = 0;
  while ( i < n)
  { 
    if (cost[i] + sum <= x && i<cost.size())
    {
      q.push(cost[i]);
      maxi = max((int)q.size(), maxi);
      sum += cost[i];
      i++;
    }
    else if (q.size() > 0 && i<cost.size())
      {
        int first = q.front();
        q.pop();
        sum -= first;
      }
      
  }
  cout<<maxi<<endl;

  //vector<vector<int> >dp(n+1,vector<int>(n+1,0));

  //int l;

  /*for(i=1;i<n+1;i++)
    {
      flag=0;
      for(j=1,l=i;j<x+1;j++,l++)
      {
        if(cost[l-1]+dp[i][j-1]<=x)
        {
          if(cost[l-1]+dp[i][j-1])
          dp[i][j]=cost[l-1]+dp[i][j-1];      
        }
        else
        {
            dp[i][j]=dp[i][j-1];
        }
        if(dp[i][j]==x)
        {
          for(int k=j;k>=1;k--)
          {
            if(dp[i][k-1]==dp[i][k])
            {
                flag=1;
                break;
            }
          }
          if(flag==0)
          {
            cout<<j<<endl;
            return;
          }
        }
      }
    }
    cout<<n<<endl;*/
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
