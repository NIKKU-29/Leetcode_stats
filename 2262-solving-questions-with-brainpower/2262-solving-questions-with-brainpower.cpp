class Solution {
public:

    long long solver(int idx ,vector<vector<int>>&questions,vector<long long>&dp)
    {
        if(idx >= questions.size()) return 0;

        if(dp[idx]!= -1) return dp[idx];

        long long take = questions[idx][0] + solver(idx+questions[idx][1] + 1 , questions,dp);
        long long notake = solver(idx+1,questions,dp);

        return dp[idx] = max(take , notake);

    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size(),-1);
        return solver(0,questions,dp);
    }
};