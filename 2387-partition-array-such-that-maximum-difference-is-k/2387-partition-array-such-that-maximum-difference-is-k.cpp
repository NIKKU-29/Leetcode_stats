class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

            int n = nums.size();
            sort(nums.begin(),nums.end());

            int mini = nums[0];
            int count = 0;

            for(int i = 1 ; i < n ; i++)
            {
                if(nums[i] - mini > k)
                {
                    count++;
                    mini = nums[i];
                }
            }

            return count+1;
    }
};