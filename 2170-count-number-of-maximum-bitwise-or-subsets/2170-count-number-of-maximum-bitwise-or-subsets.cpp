class Solution {
public:

    void solver(int idx, int mask, int curr, vector<int>& nums, int& c) {
        if (idx == nums.size()) {
            if (curr == mask) c++;
            return;
        }

        solver(idx + 1, mask, curr | nums[idx], nums, c);
        solver(idx + 1, mask, curr, nums, c);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int mask = 0;
        for (auto elem : nums) {
            mask |= elem;
        }

        int count = 0;
        solver(0, mask, 0, nums, count);
        return count;
    }
};
