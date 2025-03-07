class Solution {
public:


    int solver(string op,string s)
    {   
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=1 ; i<=n ;i++)
        {
            for(int j=1 ;j<=n ;j++)
            {

                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }

                else if(op[i-1]==s[j-1])
                {
                    dp[i][j]= 1 + dp[i-1][j-1] ;
                }

                else{

                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

                }
            }
        }

        return dp[n][n];
    }

    int longestPalindromeSubseq(string s) {
        
        string op = s;
        int n=s.size();
        reverse(op.begin(),op.end());
        return solver(op,s);

    }
};