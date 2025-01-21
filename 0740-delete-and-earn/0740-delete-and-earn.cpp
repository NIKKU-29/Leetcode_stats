class Solution {
public:

    int solver(int idx,vector<int>&freq,vector<int>&dp)
    {
        if(idx >= freq.size())
        {
            return 0;
        }

        if(dp[idx]!=0)
        {
            return dp[idx];
        }

        int take = freq[idx] + solver(idx+2,freq,dp);
        int notake = solver(idx+1,freq,dp);

        return dp[idx]=max(take,notake);

    }

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
        return solver(0,freq,dp);
    }
};
