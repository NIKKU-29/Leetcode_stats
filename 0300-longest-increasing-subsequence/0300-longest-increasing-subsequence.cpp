class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       
        vector<int> LIS;
        for (int len = 0 ; len < nums.size(); len++) {
            if (LIS.empty() || LIS.back() < nums[len]) {
                LIS.push_back(nums[len]);
            } else {
                auto it = lower_bound(LIS.begin(),LIS.end(),nums[len]);
                *it = nums[len];
            }
        }
        return LIS.size(); 
    }
};