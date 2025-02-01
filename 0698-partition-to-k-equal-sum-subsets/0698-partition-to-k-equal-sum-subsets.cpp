class Solution {
public:

    bool solver(int k,int idx,int currsum,int target,vector<int>&nums)
    {
            if(k==0) return true;
            if(currsum == target)
            {
                return solver(k-1,0,0,target,nums);
            }
            
           

            for(int i=idx ; i < nums.size() ;i++)
            {
                if(nums[i]==-1) continue;

                            
                if(currsum + nums[i] <= target)
                {
                    int temp=nums[i];
                    nums[i]=-1;
                    if(solver(k,i+1,currsum+temp,target,nums)) return true;
                    nums[i]=temp;

                }
                
            }

            return false;
            
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0) return false;
        int target=sum/k;
        sort(nums.begin(),nums.end(),greater<int>());
        return solver(k,0,0,target,nums);
    }
};