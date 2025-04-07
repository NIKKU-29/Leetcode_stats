class Solution {
public:
    vector<vector<int>> dp;

    bool solver(int idx, int target, vector<int>& nums) {
        if (target == 0) return true;
        if (idx == nums.size() || target < 0) return false;
        if (dp[idx][target] != -1) return dp[idx][target];

        bool take = solver(idx + 1, target - nums[idx], nums);
        bool notake = solver(idx + 1, target, nums);

        return dp[idx][target] = take || notake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;

        dp = vector<vector<int>>(nums.size(), vector<int>(target + 1, -1));
        return solver(0, target, nums);
    }
};
