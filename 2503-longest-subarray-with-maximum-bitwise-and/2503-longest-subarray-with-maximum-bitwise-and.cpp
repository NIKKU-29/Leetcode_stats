class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Find the maximum element in the array
        int target = *max_element(nums.begin(), nums.end());
        
        int maxfreq = 0; // To store the longest subarray length
        int currfreq = 0; // To track the current subarray length
        
        // Iterate through the array once (O(n) time complexity)
        for (int num : nums) {
            // Increment currfreq if num equals target, else reset it
            currfreq = (num == target) ? currfreq + 1 : 0;
            // Update maxfreq with the maximum value of currfreq found so far
            maxfreq = max(maxfreq, currfreq);
        }

        return maxfreq;
    }
};
