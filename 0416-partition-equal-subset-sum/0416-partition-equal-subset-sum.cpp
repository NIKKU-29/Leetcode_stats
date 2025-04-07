class Solution {
public:
  

    bool solver(int idx, int target, vector<int>& nums,vector<vector<int>>&dp) {
        if (target == 0) return true;
        if (idx == nums.size() || target < 0) return false;
        if (dp[idx][target] != -1) return dp[idx][target];

        bool take = solver(idx + 1, target - nums[idx], nums,dp);
        bool notake = solver(idx + 1, target, nums,dp);

        return dp[idx][target] = take || notake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int n = nums.size();
        int target = sum / 2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        return solver(0, target, nums,dp);
    }
};
