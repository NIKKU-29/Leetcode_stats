class Solution {
public:


    int solver(string op,string s)
    {   
        int n=s.size();
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);

        for(int i=1 ; i<=n ;i++)
        {
            for(int j=1 ;j<=n ;j++)
            {

                // if(i==0 || j==0)
                // {
                //     curr[i]=0;
                // }

                if(op[i-1]==s[j-1])
                {
                    curr[j]=prev[j-1] + 1;
                }

                else{

                    curr[j]=max(prev[j],curr[j-1]);

                }
            }

            prev=curr;
        }

        return prev[n];
    }

    int longestPalindromeSubseq(string s) {
        
        string op = s;
        int n=s.size();
        reverse(op.begin(),op.end());
        return solver(op,s);

    }
};