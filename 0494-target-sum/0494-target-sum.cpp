
class Solution {
public:
    int solver(int index, int curr, int target, vector<int>& nums, vector<vector<int>>& dp) { 
        int n = nums.size();
        if (index == n) {
            if (curr == target) return 1;
            return 0;
        }
        if (dp[index][curr + 1000] != -1) {
            return dp[index][curr + 1000];
        }

        int positive = solver(index + 1, curr + nums[index], target, nums, dp);
        int negative = solver(index + 1, curr - nums[index], target, nums, dp);

        return dp[index][curr + 1000] = positive + negative;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1)); 
        return solver(0, 0, target, nums, dp);
    }
};
