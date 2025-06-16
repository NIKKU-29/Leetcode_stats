class Solution {
public:

    

    int solver(int idx,int currsum , vector<vector<int>>&dp , int target , vector<int>& nums)
    {
        int n=nums.size();
        if(idx==n)
        {
            if(currsum==target)
            {
                return 1;
            }

            return 0;
        }

        if(dp[idx][currsum + 1000]!=-1)
        {
            return dp[idx][currsum+1000];
        }


        int plus=solver(idx+1,currsum+nums[idx],dp,target,nums);
        int neg=solver(idx+1,currsum-nums[idx],dp,target,nums);

        return dp[idx][currsum+1000]=plus + neg;
        
    }


    int findTargetSumWays(vector<int>& nums, int target) {

        int n=nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001, -1));
        int count=solver(0,0,dp,target,nums);
        return count;
    }
};