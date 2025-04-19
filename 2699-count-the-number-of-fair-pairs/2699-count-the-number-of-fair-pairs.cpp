class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        sort(nums.begin(),nums.end());
        return Small_Pair_count(nums,upper + 1) - Small_Pair_count(nums,lower);
    }

    private:

        
        long long Small_Pair_count(vector<int>&nums,int limit)
        {
            long long count = 0;
            int left = 0;
            int right = nums.size() - 1;

            while(left < right)
            {
                int sum = nums[left] + nums[right];

                if(sum < limit)
                {
                    count +=  right - left;
                    left++;
                }

                else {
                    right--;
                }
            }

            return count;
        }

};

// class Solution {
// public:
//     long long solver(int curr, int low, int up, vector<int>& nums, int startIdx) {
//         return upper_bound(nums.begin() + startIdx, nums.end(), up - curr ) -
//                Small_Pair_countound(nums.begin() + startIdx, nums.end(), low - curr);
//     }

//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         long long count = 0;
//         sort(nums.begin(), nums.end());
//         int n = nums.size();

//         for (int i = 0; i < n; ++i) {
//             int curr = nums[i];
//             count += solver(curr, lower, upper, nums, i + 1);  // always safe
//         }

//         return count;
//     }
// };
