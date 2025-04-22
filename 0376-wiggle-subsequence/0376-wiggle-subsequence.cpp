class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
       int n = nums.size();
    if (n < 2) return n;
    
    // Initialize states: up represents length ending with an up difference,
    // down represents length ending with a down difference
    int up = 1, down = 1;
    
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i-1]) {
            // Current element is greater - can form an up wiggle
            // We extend the previous down sequence
            up = down + 1;
        } else if (nums[i] < nums[i-1]) {
            // Current element is smaller - can form a down wiggle
            // We extend the previous up sequence
            down = up + 1;
        }
        // If nums[i] == nums[i-1], we can't form a wiggle - up and down remain the same
    }
    
    return max(up, down);
    }
};