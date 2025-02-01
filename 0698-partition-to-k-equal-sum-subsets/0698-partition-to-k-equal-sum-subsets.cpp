class Solution {
public:
    bool solver(int k, int idx, int currsum, int target, vector<int>& nums, vector<bool>& visited) {
        if (k == 0) return true;
        
        if (currsum == target) {
            return solver(k - 1, 0, 0, target, nums, visited);
        }

        // Start from idx to avoid duplicates
        for (int i = idx; i < nums.size(); i++) {
            if (visited[i]) continue;  // Skip if already used
            
            // If current number would exceed target, just continue to next number
            // instead of returning or backtracking
            if (currsum + nums[i] > target) {
                continue;
            }
            
            visited[i] = true;
            if (solver(k, i + 1, currsum + nums[i], target, nums, visited)) {
                return true;
            }
            visited[i] = false;
            
            // Key pruning optimization: if we failed with currsum = 0,
            // no need to try other numbers as they'll be smaller
            if (currsum == 0) {
                return false;
            }
            
            // Skip duplicates to avoid trying same combinations
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        
        if (nums[0] > target) return false;
        
        vector<bool> visited(nums.size(), false);
        return solver(k, 0, 0, target, nums, visited);
    }
};