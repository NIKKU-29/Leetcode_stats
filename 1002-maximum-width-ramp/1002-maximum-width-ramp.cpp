class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromleft(n), fromright(n);
        
        // Compute the minimum prefix array
        fromleft[0] = nums[0];
        for (int i = 1; i < n; i++) {
            fromleft[i] = min(fromleft[i - 1], nums[i]);
        }

        // Compute the maximum suffix array
        fromright[n - 1] = nums[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            fromright[j] = max(fromright[j + 1], nums[j]);
        }

        // Use two pointers to find max(j - i)
        int i = 0, j = 0, ans = 0;
        while (j < n) {
            if (fromleft[i] <= fromright[j]) {
                ans = max(ans, j - i);
                j++; // Try to maximize width by moving `j`
            } else {
                i++; // If condition fails, move `i` forward
            }
        }
        
        return ans;
    }
};
