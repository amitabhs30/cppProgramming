//#include<bits/stdc++.h>
#include "/Users/amitabh/stdc++.h"

using namespace std;

#define ff              first
#define ss              second
#define ll				long long
#define pb              push_back
#define mp              make_pair
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define deb(x) 			cout << #x << "=" << x << endl
#define fo(i,n)			for(i=0;i<n;i++)
#define Fo(i,k,n) 		for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef unordered_set<int, int> usii;
typedef unordered_map<int, int> umii;
typedef map<int,int> mii;

int mpow(int base, int exp);

bool sorte(const pair<ll,ll>&a,const pair<ll,ll>&b){
	
	return (a.second>b.second);

}

void solve()
{	long long i,j,k,n,x,y;

	cin>>n>>x>>y;
	vector<long long>a(n);
	vector<long long>b(n);
	vector<pair<ll,ll> >d(n);

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		d[i].first=i;
		d[i].second=abs(a[i]-b[i]);
	}
	sort(d.begin(),d.end(),sorte);
	int aAs=0,bAs=0,val=0;

	for(auto e: d)
	{
		if(aAs+bAs>=n)
		{
			break;
		}
		if(a[e.first]>b[e.first])
		{
			if(aAs+1<=x)
			{
				aAs++;
				val+=a[e.first];
			}
			else
			{
				bAs++;
				val+=b[e.first];
			}
		}
		else
		{
			if(bAs+1<=y)
			{
				bAs++;
				val+=b[e.first];
			}
			else
			{
				aAs++;
				val+=a[e.first];
			}
			
		}
		
	}
	cout<<val<<endl;
	

}

void startup()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

int mpow(int base, int exp) {

  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

