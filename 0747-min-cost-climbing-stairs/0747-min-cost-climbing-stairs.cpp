class Solution {
public:

    int solver(int idx ,vector<int>&cost,vector<int>&dp)
    {
        if(idx >= cost.size())
        {
            return 0;
        }

        if(dp[idx]!=-1) return dp[idx];

        int jump1=cost[idx] + solver(idx+1,cost,dp);
        int jump2=cost[idx] + solver(idx+2,cost,dp);

        return dp[idx]=min(jump1,jump2);
    }

    int minCostClimbingStairs(vector<int>& cost) { 
        int n=cost.size();
        vector<int>dp(n,-1);       
        return min(solver(0,cost,dp),solver(1,cost,dp));
    }
};