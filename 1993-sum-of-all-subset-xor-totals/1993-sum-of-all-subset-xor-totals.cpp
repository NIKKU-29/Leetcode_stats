class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalOR = 0;

        for (int num : nums) {
            totalOR |= num;
        }

        int n = nums.size();
        return totalOR * (1 << (n - 1));
    }
};
