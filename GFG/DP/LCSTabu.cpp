#include<iostream>
#include<vector>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size();
	int m=s2.size();
	vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int i=0;i<=m;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			if(s1[i-1]==s2[j-1])
	 		{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<"  ";
	for(int i=0;i<m;i++)
	{
		cout<<s2[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{	cout<<s1[i-1]<<" ";
		for(int j=1;j<=m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[n][m];
	return 0;
}