class Solution {
public:
   

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));;
        

        //  for(int idx = 0 ;idx <= n ;idx++)
        // {
        //     dp[idx][0][2] = 0;
        //     dp[idx][1][2] = 0;
        // }

        // for(int txnCount = 0 ;txnCount <= 2 ; txnCount++)
        // {   
        //     dp[n][0][txnCount] = 0;
        //     dp[n][1][txnCount] = 0;
        // }
        


        for (int idx = n - 1; idx >= 0; idx--) {
            for (int mode = 0; mode <= 1; mode++) {
                for (int txnCount = 1; txnCount <= 2; txnCount++) {

                    int profit=0;

                     if (mode == 0) { // Buy Mode
                    int buy = -prices[idx] + dp[idx+1][1][txnCount];
                    int notBuy = dp[idx+1][0][txnCount];
                    profit = max(buy, notBuy);
                    }

                else { // Sell Mode
                    int sell = prices[idx] + dp[idx+1][0][txnCount-1];
                    int notSell = dp[idx+1][1][txnCount];
                    profit = max(sell, notSell);
                }

                    dp[idx][mode][txnCount] = profit;
                }
            }
        }


        return dp[0][0][2];
    }
};
