class Solution {
public:
    int solver(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == nums.size()) return 0; // Base case: if no elements are left, LIS length is 0

        if (dp[idx][prev + 1] != -1) return dp[idx][prev + 1];
        
        // Not taking the current element
        int not_take = solver(idx + 1, prev, nums,dp);
        
        // Taking the current element, if it's greater than the previous element in the subsequence
        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + solver(idx + 1, idx, nums,dp);
        }
        
        return dp[idx][prev + 1] = max(take, not_take); // Return the maximum of the two choices
    }

    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solver(0, -1, nums,dp); // Start recursion with index 0 and no previous element
    }
};
