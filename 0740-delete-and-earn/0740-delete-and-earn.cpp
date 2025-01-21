class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        for (int num : nums) {
            maxNum = max(maxNum, num);
        }

        // Create a frequency array
        vector<int> freq(maxNum + 1, 0);
        for (int num : nums) {
            freq[num] += num; // Total value for the number
        }

        // DP array to solve the house robber problem
        vector<int> dp(maxNum + 1, 0);
        dp[1] = freq[1]; // Base case: Only take the first number
        
        for (int i = 2; i <= maxNum; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + freq[i]);
        }

        return dp[maxNum];
    }
};
