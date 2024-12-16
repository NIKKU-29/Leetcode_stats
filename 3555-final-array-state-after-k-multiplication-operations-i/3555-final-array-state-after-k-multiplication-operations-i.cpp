class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {


        while(k--)
        {
            auto mini=min_element(nums.begin(),nums.end());
            int index = distance(nums.begin(), mini);

            nums[index]*=multiplier;
        }
        
        return nums;
    }
};