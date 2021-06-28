class Solution {
public:

    bool PredictTheWinner(vector<int>& nums) {
    	int n=nums.size();
    	vector<vector<int> >dp(n+1,vector<int>(n+1));
    	for(int i=0;i<n;i++)
    	{
    		dp[i][i+1]=max(nums[i],nums[i+1]);
    	}
    	for(int gap=3;gap<n;gap+=2)
    	{
    		for(int i=0;i+gap<n;i++)
    		{
    			int j=gap+i;
    			dp[i][j]=max(nums[i]+min(dp[i+2][j],dp[i+1][j-1]),
    						 nums[j]+min(dp[i+1][j-1],dp[i][j-2]));
    		}
    	}
    	int sum=0;
    	for(int i=0;i<n;i++)
    	{
    		sum+=nums[i];
    	}
	   	int res;
    	if(n&1)
    		 res=dp[0][n-2]+dp[1][n-1];
    	else 
    		res=dp[0][n-1];
    	return res>=sum-res?true:false;

    }
};