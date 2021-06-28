//#include<bits/stdc++.h>
#include "/Users/amitabh/stdc++.h"

// #include<iostream>
// #include<vector>
// #include<unordered_set>
// #include<unordered_map>
// #include<set>
// #include<map>


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
	int n;
	cin>>n;

	char ar[n][n];
	pair<int,int>p1;
	pair<int,int>p2;
	pair<int,int>p3;
	pair<int,int>p4;
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>ar[i][j];
			char ch=ar[i][j];
			if(ch=='*'&&flag)
			{
				p1.first=i;
				p1.second=j;
				flag=false;
			}
			else if(ch=='*'&&!flag)
			{
				p2.first=i;
				p2.second=j;
			}	
		}
	}
	if(p1.first==p2.first||p1.second==p2.second)
	{
		if(p1.first==p2.first)
		{
			if(p1.first==n-1)
			{
				p3.first=p1.first-1;
				p4.first=p1.first-1;
				p3.second=p1.second;
				p4.second=p2.second;
			}
			else{
				p3.first=p1.first+1;
				p4.first=p1.first+1;
				p3.second=p1.second;
				p4.second=p2.second;	
			}
		}
		else{
			if(p1.second==n-1)
			{
				p3.second=p1.second-1;
				p4.second=p1.second-1;
				p3.first=p1.first;
				p4.first=p2.first;
			}
		}
	}
	else{
		p3.first=p1.second;
		p3.second=p2.first;
		p4.first=p2.second;
		p4.second=p1.first;
	}

	ar[p3.first][p3.second]='*';
	ar[p4.first][p4.second]='*';

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ar[i][j];
		}
		cout<<endl;
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
	w(t)
	{
		solve();
	}
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
