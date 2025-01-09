class Solution {
public:
    long long solve(vector<int> &nums)
    {
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }

        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int select = nums[i] + prev2;
            int skip = prev1;
            prev2 = prev1;
            prev1 = max(select, skip);
        }
        return prev1;
    }

    long long rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }

        vector<int> v1, v2;

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                v1.push_back(nums[i]);
            if (i != n - 1)
                v2.push_back(nums[i]);
        }

        int ans = max(solve(v1), solve(v2));
        return ans;
    }
};