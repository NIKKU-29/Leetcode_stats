class Solution {
public:

    int solver(int idx,int n,vector<int>&dp,vector<int>& days, vector<int>& costs)
    {
        if(idx==n) return 0;

        if(dp[idx]!=-1)  return dp[idx];
        
        //1 day passes
        int total1=costs[0] + solver(idx+1,n,dp,days,costs);

        //7 day passes
        int idx7=idx;
        int newdays= days[idx] + 7; //now pass lasts upto current + 7 days;
        
        while(idx7 < n && newdays > days[idx7])
        {
            idx7++;
        }

        int total7=costs[1] + solver(idx7,n,dp,days,costs);

        //30 day passes
        int idx30=idx;
        newdays= days[idx] + 30; //now pass lasts upto current + 7 days;
        
        while(idx30 < n && newdays > days[idx30])
        {
            idx30++;
        }

        int total30=costs[2] + solver(idx30,n,dp,days,costs);


        return dp[idx] = min(total1,min(total7,total30));


    }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n,-1);
        return solver(0,n,dp,days,costs);
        
    }
};