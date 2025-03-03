class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;

        for (int num : nums) {
            if (num < pivot) less.push_back(num);
            else if (num == pivot) equal.push_back(num);
            else greater.push_back(num);
        }

        // Concatenate all parts efficiently
        vector<int> ans;
        ans.reserve(nums.size()); // Allocate memory in advance
        ans.insert(ans.end(), less.begin(), less.end());
        ans.insert(ans.end(), equal.begin(), equal.end());
        ans.insert(ans.end(), greater.begin(), greater.end());

        return ans;
    }
};
