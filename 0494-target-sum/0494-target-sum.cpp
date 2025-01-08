class Solution {
public:

    int solver(int idx, int sum , vector<int>& nums, int target )
    {
        int n=nums.size();

        if(sum==target && idx==n)
        {
            return 1;
        }

        else if(idx==n) return 0;

        int plus=solver(idx+1,sum+nums[idx],nums,target);
        int neg=solver(idx+1,sum-nums[idx],nums,target);

        return plus+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solver(0,0,nums,target);
    }
};