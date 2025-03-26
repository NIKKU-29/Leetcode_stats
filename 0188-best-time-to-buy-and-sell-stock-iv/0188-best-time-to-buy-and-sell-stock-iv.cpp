class Solution {
public:

        int solver(int idx, int mode, int txnCount, vector<int>& prices, vector<vector<vector<int>>>& dp,int k) {
        if (idx == prices.size() || txnCount == k) return 0; // Max  transactions

        if (dp[idx][mode][txnCount] != -1) return dp[idx][mode][txnCount];

        int profit = 0;
        if (mode == 0) { // Buy Mode
            int buy = -prices[idx] + solver(idx+1, 1, txnCount, prices, dp,k);
            int notBuy = solver(idx+1, 0, txnCount, prices, dp,k);
            profit = max(buy, notBuy);
        } else { // Sell Mode
            int sell = prices[idx] + solver(idx+1, 0, txnCount+1, prices, dp,k);
            int notSell = solver(idx+1, 1, txnCount, prices, dp,k);
            profit = max(sell, notSell);
        }

        return dp[idx][mode][txnCount] = profit;
    }


    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solver(0, 0, 0, prices, dp,k);
    }
};

