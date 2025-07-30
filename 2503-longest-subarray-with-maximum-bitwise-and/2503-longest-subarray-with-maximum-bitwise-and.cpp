class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxand = *max_element(nums.begin(),nums.end());
        int count = 0;
        int ans = 0;
        
        for(auto elem : nums)
        {
            if(elem == maxand) count++;
            else count = 0;
            ans = max(ans,count);
        }

        return ans;
    }
};