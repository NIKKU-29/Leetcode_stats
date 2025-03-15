class Solution {
public:
    bool canSteal(vector<int>& nums, int capability, int k) {
        int count = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] <= capability) {
                count++;
                i += 2; // Skip the adjacent house
            } else {
                i++; // Move to the next house
            }
            if (count >= k) return true;
        }
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int left = 1;
        int right = 1e9; // Maximum possible value in the array
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSteal(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};