class Solution {
public:

    int solver(int mid , vector<int>&nums)
    {   
        int count = 0;

        for(int i = 0 ; i < nums.size()-1 ; i++)
        {
            if(nums[i+1] - nums[i] <= mid)
            {
                count++;
                i++;
            }
        }

        return count;
    }


    int minimizeMax(vector<int>& nums, int p) {

            int n = nums.size();
            sort(nums.begin(),nums.end());
            int l = 0;
            int r = nums[n-1] - nums[0];


            while(l < r)
            {
                int mid = l + (r - l)/2;

                if(solver(mid,nums) >= p)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }

            
            return l;
    }
};