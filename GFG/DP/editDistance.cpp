#include<iostream>
#include<vector>

using namespace std;


int editDistance(string s1,string s2,int n,int m){	//recursive solution
	if(n==0)
		return m;
	if(m==0)
		return n;
	if(s1[n-1]==s2[m-1])
	{
		return editDistance(s1,s2,n-1,m-1);
	}
	else
	{
		int x=min(editDistance(s1,s2,n,m-1),editDistance(s1,s2,n-1,m));
		return 1+min(x,editDistance(s1,s2,n-1,m-1));
	}
}
int editDistanceDp(string s1,string s2,int n,int m)
{
	int dp[n+1][m+1];
	dp[0][0]=0;
	for(int i=1;i<=m;i++)
	{
		dp[i][0]=i;
		dp[0][i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				int x=min(dp[i-1][j],dp[i][j-1]);
				dp[i][j]=1+min(x,dp[i-1][j-1]);
			}
		}
	}
	return dp[n][m];
}


int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s1,s2;
	cin>>s1>>s2;
	//cout<<s1<<endl;
	cout<<editDistanceDp(s1,s2,s1.size(),s2.size());

	return 0;
}