class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // Create a map to store value -> index mapping
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        
        // dp[i][j] represents the length of Fibonacci sequence ending with arr[i] and arr[j]
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxLen = 0;
        
        // For each pair of numbers
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < j; i++) {
                // Current pair: arr[i], arr[j]
                // We need to find if there's a number arr[k] where k < i
                // such that arr[k] + arr[i] = arr[j]
                int diff = arr[j] - arr[i];
                
                if(diff < arr[i] && mp.find(diff) != mp.end()) {
                    int k = mp[diff];
                    if(k < i) {
                        dp[i][j] = dp[k][i] + 1;
                        maxLen = max(maxLen, dp[i][j]);
                    }
                }
            }
        }
        
        return maxLen >= 3 ? maxLen : 0;
    }
};