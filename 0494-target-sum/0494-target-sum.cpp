class Solution {
public:

    int solver(int idx, int sum , vector<int>& nums, int target,vector<vector<int>>&dp)
    {
        int n=nums.size();

        if(idx==n)
        {
           if(sum==target) return 1;
           return 0;
        }

        

        if(dp[idx][sum+1000]!=-1)
        {
            return dp[idx][sum+1000];
        }

        int plus=solver(idx+1,sum+nums[idx],nums,target,dp);
        int neg=solver(idx+1,sum-nums[idx],nums,target,dp);

        return dp[idx][sum+1000]=plus+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return solver(0,0,nums,target,dp);
    }
};