class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum=0;
        int ans=INT_MIN;

        for(auto elem : nums)
        {
            sum+=elem;
            ans=max(sum,ans);
            if(sum < 0)
            {
                sum=0;
            }
        }
        
        return ans;
    }
};