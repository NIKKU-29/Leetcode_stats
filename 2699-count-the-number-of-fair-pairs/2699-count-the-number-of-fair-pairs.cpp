class Solution {
public:
    long long solver(int curr, int low, int up, vector<int>& nums, int startIdx) {
        return upper_bound(nums.begin() + startIdx, nums.end(), up - curr ) -
               lower_bound(nums.begin() + startIdx, nums.end(), low - curr);
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int curr = nums[i];
            count += solver(curr, lower, upper, nums, i + 1);  // always safe
        }

        return count;
    }
};
