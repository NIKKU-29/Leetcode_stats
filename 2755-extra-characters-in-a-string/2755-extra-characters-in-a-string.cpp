class Solution {
public:

    int dp[51];

    int helper(int i,int n,string&s ,unordered_set<string>st)
    {
        if(i>=n)
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int result= 1 + helper(i+1,n,s,st);

        for(int j=i;j<n;j++)
        {
            string curr=s.substr(i,j-i+1);

            if(st.count(curr))
            {
                result= min(result,helper(j+1,n,s,st));
            }
        }

        return dp[i]=result;
    }


    int minExtraChar(string s, vector<string>& dic) {

        memset(dp,-1,sizeof(dp));
        int n=s.size();
        unordered_set<string>st(dic.begin(),dic.end());
        return helper(0,n,s,st);
    }
};