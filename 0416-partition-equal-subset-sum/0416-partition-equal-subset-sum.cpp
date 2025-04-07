// class Solution {
// public:
  

//     bool solver(int idx, int target, vector<int>& nums,vector<vector<int>>&dp) {
//         if (target == 0) return true;
//         if (idx == nums.size() || target < 0) return false;
//         if (dp[idx][target] != -1) return dp[idx][target];

//         bool take = solver(idx + 1, target - nums[idx], nums,dp);
//         bool notake = solver(idx + 1, target, nums,dp);

//         return dp[idx][target] = take || notake;
//     }

//     bool canPartition(vector<int>& nums) {
//         int t = accumulate(nums.begin(), nums.end(), 0);
//         if (t % 2 != 0) return false;
//         int n = nums.size();
//         int target = t / 2;
//         vector<vector<int>> dp(n+1,vector<int>(t+1,-1));
        
//         return solver(0, target, nums,dp);
//     }
// };







class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t = accumulate(nums.begin(), nums.end(), 0);
        if (t % 2 != 0) return false;
        int n = nums.size();
        int target = t / 2;
        vector<vector<int>> dp(n+1,vector<int>(t+1,0));

        for(int idx = 0 ; idx <=n ; idx++)
        {
            dp[idx][0] = true;
        }
        
        for(int idx = n-1 ; idx >= 0 ;idx--)
        {
            for(int t = 0 ; t <= target ; t++)
            {
                bool notake = dp[idx+1][t];

                bool take = false;
                if(t >= nums[idx]) {
                    take = dp[idx+1][t-nums[idx]];
                }
                
                dp[idx][t] = take || notake;
            }
        }

        return dp[0][target];
    }
};
