// class Solution {
// public:

//     long long solver(int idx ,vector<vector<int>>&questions,vector<long long>&dp)
//     {
//         if(idx >= questions.size()) return 0;

//         if(dp[idx]!= -1) return dp[idx];

//         long long take = questions[idx][0] + solver(idx+questions[idx][1] + 1 , questions,dp);
//         long long notake = solver(idx+1,questions,dp);

//         return dp[idx] = max(take , notake);

//     }

//     long long mostPoints(vector<vector<int>>& questions) {
//         vector<long long>dp(questions.size(),-1);
//         return solver(0,questions,dp);
//     }
// };


class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long>dp(n+1,0);
           

           for(int idx = n-1; idx>=0 ;idx--)
           {

                long long take = questions[idx][0] + (idx + questions[idx][1] + 1 < n ? dp[idx + questions[idx][1] + 1] : 0);
                long long notake = dp[idx+1];

                 dp[idx] = max(take , notake);              
           }


           return dp[0];

    }
};