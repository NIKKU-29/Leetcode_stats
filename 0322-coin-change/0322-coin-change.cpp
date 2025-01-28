class Solution {
public:

    int solver(int idx,vector<int>& coins,int amount,vector<vector<int>>& dp)
    {
        if(amount < 0) return INT_MAX;

        if(idx == coins.size())
        {
            if(amount==0) return 0;
            else return INT_MAX;
        }

        if (dp[idx][amount] != -1) return dp[idx][amount];
        
        int take= solver(idx,coins,amount-coins[idx],dp);
        if(take!=INT_MAX) take+=1;
        int notake= solver(idx+1,coins,amount,dp);

        
        return dp[idx][amount]=min(take,notake);

    }


    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solver(0, coins, amount,dp);
        return result == INT_MAX ? -1 : result;
    }
};