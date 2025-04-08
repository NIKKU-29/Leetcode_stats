class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        while (true) {
            set<int> st(nums.begin(), nums.end());
            if (st.size() == nums.size()) {
                break; // All elements are unique now
            }

            // Remove first 3 elements or all if < 3
            int k = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + k);
            count++;
        }
        return count;
    }
};
