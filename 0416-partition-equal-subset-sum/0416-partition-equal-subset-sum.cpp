class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            sum += num;
        }

        // If sum is odd, cannot partition into two subsets with equal sum
        if (sum % 2 != 0) {
            return false;
        }

        int k = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

        // Initialize dp[i][0] = true for all i
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Initialize dp[0][nums[0]] if nums[0] <= k
        if (nums[0] <= k) {
            dp[0][nums[0]] = true;
        }

        // Fill the DP table
        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= k; target++) {
                bool notake = dp[idx - 1][target];
                bool take = false;
                if (nums[idx] <= target) {
                    take = dp[idx - 1][target - nums[idx]];
                }
                dp[idx][target] = take || notake;
            }
        }

        // The result will be in dp[n-1][k]
        return dp[n - 1][k];
    }
};
