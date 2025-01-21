class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        long long sumup=0;
        long long sumdown=0;

        long long ans=LLONG_MAX;

        for(int i=0 ;i< grid[0].size() ;i++)
        {   
            sumup+=grid[0][i];
        }

        for(int i=0 ;i< grid[0].size() ; i++)
        {
            sumup-=grid[0][i];

            ans=min(ans,max(sumup,sumdown));

            sumdown+=grid[1][i];

        }

        return ans;
        
    }
};