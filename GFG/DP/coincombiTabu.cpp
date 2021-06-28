#include<iostream>
#include<vector>

using namespace std;


int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n,sum;
	cin>>n>>sum;
	vector<int>coins(n);
	for(int i=0;i<n;i++)
	{
		cin>>coins[i];
	}
	vector<vector<int>>dp(sum+1,vector<int>(n+1));

	for(int i=0;i<=n;i++)
	{
		dp[0][i]=1;
	}
	for(int i=1;i<=sum;i++)
	{
		dp[i][0]=0;
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(i>=coins[j-1])
			{
				dp[i][j]+=dp[i-coins[j-1]][j];
			}
		}
	}
	for(int i=0;i<=sum;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}