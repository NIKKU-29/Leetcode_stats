class Solution {
public:
    int odd_even(const vector<int>& nums)
    {
        int ans = 0;
        int prev = -1;
        int count = 0;
        for (auto current : nums)
        {
            if (prev == -1)
            {
                prev = current;
                count++;
            }
            else
            {
                if ((prev & 1) != (current & 1)) // alternating parity
                {
                    count++;
                    prev = current;
                }
               
            }
            ans = max(ans, count);
        }
        return ans;
    }

    int odd(const vector<int>& nums)
    {
        int count = 0;
        for (int x : nums)
        {
            if (x % 2 == 1) count++; // pick all odd elements
        }
        return count;
    }

    int even(const vector<int>& nums)
    {
        int count = 0;
        for (int x : nums)
        {
            if (x % 2 == 0) count++; // pick all even elements
        }
        return count;
    }

    int maximumLength(vector<int>& nums) {
        return max({odd_even(nums), odd(nums), even(nums)});
    }
};
