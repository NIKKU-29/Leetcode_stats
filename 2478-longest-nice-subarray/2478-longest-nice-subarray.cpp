class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int mask = 0,left = 0,right = 0;
        int n = nums.size();
        int ans =1;

        while(right < n)
        {

            while(mask & nums[right])   //revoke not valid so extrcat left ones
            {
                int leftMost = nums[left];
                mask ^= leftMost;
                left++;
            }

            mask|=nums[right];
            ans = max(ans, right - left + 1);
            right++;

        }

        return ans;
    }
};