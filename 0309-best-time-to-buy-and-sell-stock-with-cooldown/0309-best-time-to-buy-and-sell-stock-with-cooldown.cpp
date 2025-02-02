class Solution {
public:
    int solver(int idx, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        if (idx >= prices.size()) {
            return 0;
        }
        
        if (dp[idx][canBuy] != -1) {
            return dp[idx][canBuy];
        }
        
        if (canBuy) {  // Can buy stock
            int buy = solver(idx + 1, 0, prices, dp) - prices[idx];  // Buy at current price
            int skip = solver(idx + 1, 1, prices, dp);  // Skip buying
            return dp[idx][canBuy] = max(buy, skip);
        } else {  // Can sell stock
            int sell = solver(idx + 2, 1, prices, dp) + prices[idx];  // Sell and cooldown
            int skip = solver(idx + 1, 0, prices, dp);  // Skip selling
            return dp[idx][canBuy] = max(sell, skip);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solver(0, 1, prices, dp);
    }
};