class Solution {
public:

    int n;

    int solver(int idx,string&s,vector<int>&dp)
    {
        if(idx==n) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];

        int take1=solver(idx+1,s,dp);

        int take2=0;
        
        if(idx+1 < n)
        {
            string TwoDigit=s.substr(idx,2);
            if(stoi(TwoDigit) <= 26)
            {
                take2 = solver(idx+2,s,dp);
            }
        }

        return dp[idx]=take1 + take2;

    }

    int numDecodings(string s) {
        
        n=s.size();
        vector<int>dp(n,-1);
        return solver(0,s,dp);
    }
};