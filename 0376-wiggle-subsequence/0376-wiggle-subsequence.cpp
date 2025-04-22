class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
       int n = nums.size();
       if (n < 2) return n;
    
    // Start with 1 for the first element
    int count = 1;
    
    // Track previous direction: 0 = initial, 1 = increasing, -1 = decreasing
    int prevDiff = 0;
    
    for (int i = 1; i < n; i++) {
        // Calculate current difference
        int diff = nums[i] - nums[i-1];
        
        // If we have a genuine direction change or first non-zero difference
        if ((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0)) {
            count++;
            // Update direction
            prevDiff = diff;
        }
    }
    
         return count;
    }
};