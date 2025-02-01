class Solution {
public:

    bool solver(int idx,vector<int>& nums,int target,vector<vector<int>>&dp)
    {
        if(target==0) return true;
        if(target<0) return false;
        if(idx >= nums.size()) return false;

        if(dp[idx][target]!=-1) return dp[idx][target];

        bool take=solver(idx+1,nums,target-nums[idx],dp);
        bool skip=solver(idx+1,nums,target,dp);

        return dp[idx][target]= skip||take;
        
    }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));


        return solver(0,nums,target,dp);

    }
};