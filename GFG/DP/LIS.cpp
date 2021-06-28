#include<iostream>
#include<vector>

using namespace std;



void dpSol()
{
	int n;
	cin>>n;

	int arr[n];
	int dp[n];
	dp[0]=1;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	for(int i=1;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int maxe=0;
	for(auto e : dp)
	{
		maxe=max(maxe,e);
	}
	cout<<maxe;
}



int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	dpSol();
	return 0;
}