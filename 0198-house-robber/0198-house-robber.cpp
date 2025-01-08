class Solution {
public:

    int solver(int idx,vector<int>& nums,vector<int>&dp)
    {
        int n=nums.size();
        if(idx>=n)
        {
            return 0;
        }

        if(dp[idx]!=-1) return dp[idx];

        int take=nums[idx] + solver(idx+2,nums,dp);
        int notake=solver(idx+1,nums,dp);

        return dp[idx]=max(take,notake);

    }

    int rob(vector<int>& nums) {

        int n=nums.size();
        int maxi=0;
        vector<int>dp(n,-1);
        return solver(0,nums,dp); 
        
    }
};