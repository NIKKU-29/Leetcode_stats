class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
        
        // dp[i][j] = length of fib subsequence ending with arr[i] and arr[j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int result = 0;
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int prev = arr[j] - arr[i];
                
                if (prev < arr[i] && index.count(prev)) {
                    int k = index[prev];
                    dp[i][j] = dp[k][i] + 1;
                } else {
                    dp[i][j] = 2;
                }
                
                result = max(result, dp[i][j]);
            }
        }
        
        return result >= 3 ? result : 0;
    }
};