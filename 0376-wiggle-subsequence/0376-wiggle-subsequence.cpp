class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
         int n = nums.size();
    if (n < 2) return n;
    
    // dp[i][0] = length of longest wiggle subsequence ending at index i with a negative last difference
    // dp[i][1] = length of longest wiggle subsequence ending at index i with a positive last difference
    vector<vector<int>> dp(n, vector<int>(2, 1));
    
    int result = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If current number is greater than previous - can form positive difference
            if (nums[i] > nums[j]) {
                // We can extend a subsequence that ended with a negative difference
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            // If current number is less than previous - can form negative difference
            else if (nums[i] < nums[j]) {
                // We can extend a subsequence that ended with a positive difference
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        
        // Update result with the maximum of both possibilities at current index
        result = max({result, dp[i][0], dp[i][1]});
    }
    
    return result;
    }
};