class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {

        long long maxi=nums[0];
        long long ans=0;

        for(int i=1;i<nums.size();i++)
        {
            ans+=maxi;
            maxi=max(maxi,(long long)nums[i]);
        }


        return ans;
        
    }
};