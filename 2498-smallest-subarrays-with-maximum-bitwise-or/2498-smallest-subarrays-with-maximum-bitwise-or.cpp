class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);         // Each element starts with a subarray of length 1
        vector<int> bitPos(32, -1);    // Last seen index for each bit

        for (int i = n - 1; i >= 0; --i) {
            // Update last seen index for each bit
            for (int b = 0; b < 32; ++b) {
                if ((nums[i] >> b) & 1) {
                    bitPos[b] = i;
                }
            }

            // Find how far we need to go from i to include all bits
            int furthest = i;
            for (int b = 0; b < 32; ++b) {
                if (bitPos[b] != -1) {
                    furthest = max(furthest, bitPos[b]);
                }
            }

            ans[i] = furthest - i + 1;
        }

        return ans;
    }
};
