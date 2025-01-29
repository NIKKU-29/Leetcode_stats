class Solution {
public:
    
    int n;

    int solver(int idx,vector<int>&dp,vector<int>& nums,int target)
    {

        if(target==0) return 1;

        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];
        

        int count=0;

        for(int i=idx; i < n ;i++)
        {
            count +=solver(idx,dp,nums,target-nums[i]);
        }

        dp[target]=count;

        return dp[target];

    }

    int combinationSum4(vector<int>& nums, int target) {

        n=nums.size();
        vector<int>dp(target+1,-1);
        return solver(0,dp,nums,target);
         
        
    }
};