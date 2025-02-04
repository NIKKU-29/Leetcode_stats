class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int ans=0;
        int n=nums.size();
        for(int i=0 ;i< n ;i++)
        {
            int j=i;
            int sum=nums[j];
            while(j < n-1 &&  nums[j]<nums[j+1])
            {
                sum+=nums[j+1];
                j++;
            }

            ans=max(ans,sum);
        }

        return ans;
        
    }
};