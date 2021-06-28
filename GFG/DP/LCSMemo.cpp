#include<iostream>
#include<vector>

using namespace std;



int lcs(string s1,string s2,int n,int m,vector<vector<int>>&dp){
	if(n<0||m<0)
	{
		//dp[n][m]=0;
		return 0;
	}
	if(dp[n][m]!=-1)
	{
		return dp[n][m];
	}
	if(s1[n-1]==s2[m-1])
	{
		dp[n][m]= 1+lcs(s1,s2,n-1,m-1,dp);
		return dp[n][m];
	}
	else
	{
		dp[n][m]=(max(lcs(s1,s2,n,m-1,dp),lcs(s1,s2,n-1,m,dp)));
		return dp[n][m];
	}
}


int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s1,s2;
	cin>>s1>>s2;
	vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
	cout<<lcs(s1,s2,s1.length(),s2.length(),dp);
	return 0;
}