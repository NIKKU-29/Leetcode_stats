class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int L = lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        int R = upper_bound(nums.begin(),nums.end(),0) - nums.begin();
        return max((n - R),(L));
    }
};