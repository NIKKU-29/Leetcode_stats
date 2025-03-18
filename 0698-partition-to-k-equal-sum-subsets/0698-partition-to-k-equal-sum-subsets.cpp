class Solution {
public:

    bool solver(int idx,int sum,int target, int k ,vector<int>&nums)
    {
        if( k  == 1) return true;
        if(target == sum) return solver(0,0,target,k-1,nums);

        for(int i = idx ; i<nums.size() ;i++ )
        {
            if(nums[i] == -1) continue;
            int temp = nums[i];
            if(sum + nums[i] <= target)
            {
                nums[i] = -1; //mark visited
                if(solver(i+1,sum+temp,target,k,nums)) return true;
                nums[i] = temp;
                // if (sum == 0) return false;
            }
        
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % k) return false;
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        return solver(0,0,target,k,nums);
    }
};