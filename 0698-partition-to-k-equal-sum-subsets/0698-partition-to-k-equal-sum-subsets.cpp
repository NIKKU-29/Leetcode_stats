class Solution {
public:
    bool solver(int k, int idx, int currsum, int target, vector<int>& nums, vector<bool>& visited) {
        if (k == 0) return true; // If all k subsets are successfully created

        if(currsum > target) return false;
        
        if (currsum == target) {
            return solver(k - 1, 0, 0, target, nums, visited); // Start forming next subset
        }

        for (int i = idx; i < nums.size(); i++) {
            if (visited[i] || currsum + nums[i] > target) continue; // Skip used elements or exceed target

            // Choose current element
            visited[i] = true;
            if (solver(k, i + 1, currsum + nums[i], target, nums, visited)) return true;
            visited[i] = false; // Backtrack
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false; // Cannot be evenly divided
        
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>()); // Optimization

        // If the largest element is greater than `target`, it's impossible
        if (nums[0] > target) return false;

        vector<bool> visited(nums.size(), false);
        return solver(k, 0, 0, target, nums, visited);
    }
};
