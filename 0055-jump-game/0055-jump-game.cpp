class Solution {
public:
    bool solver(int idx, vector<int>& nums, vector<int>& dp) {  // Changed to vector<int>
        if(idx >= nums.size()-1) {
            return true;
        }
        
        if(dp[idx] != -1) return dp[idx];  // Changed from false to -1
        
        if(nums[idx] == 0) return false;

        for(int i = nums[idx]; i >=1; i--) {
            if(solver(idx + i, nums, dp)) {
                  // Store as 1 instead of true
                return dp[idx]=true;
            }
        }

          // Store as 0 instead of false
        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        vector<int> dp(nums.size(), -1);  // Initialize with -1
        return solver(0, nums, dp);
    }
};