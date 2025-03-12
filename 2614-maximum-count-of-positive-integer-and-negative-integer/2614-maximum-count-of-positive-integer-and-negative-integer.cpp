class Solution {
public:

    int low(vector<int>nums)
    {
        int n = nums.size();
        int l=0;
        int r=n-1;
        int idx = n;

        while(l <= r)
        {
            int mid = l + (r - l)/2;

            if(nums[mid] < 0)
            {
                l = mid + 1;
            }

            else if(nums[mid] >= 0)
            {
                r = mid - 1;
                idx = mid;
            }
        }

        return idx;
    }

    int high(vector<int>nums)
    {
        int n = nums.size();
        int l=0;
        int r=n-1;
        int idx = n;

        while(l <= r)
        {
            int mid = l + (r - l)/2;

            if(nums[mid] <= 0)
            {
                l = mid + 1;
            
            }

            else if(nums[mid] > 0)
            {
                r = mid - 1;
                idx=mid;
            }
        }

        return idx;
    }

    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        // int L = lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        // int R = upper_bound(nums.begin(),nums.end(),0) - nums.begin();

        int L = low(nums);
        int R = high(nums);
        return max((n - R),(L));
    }
};