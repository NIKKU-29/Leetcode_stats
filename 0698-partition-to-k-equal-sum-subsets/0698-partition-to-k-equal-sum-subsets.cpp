class Solution {
public:
    bool solver(vector<int>& nums, vector<int>& visited, int start_index, int k, int current_sum, int target) {
        if (k == 0) return true;  // Only one subset left, no need to check further
        if (current_sum == target) {
            // Current subset is complete, proceed to the next subset
            return solver(nums, visited, 0, k - 1, 0, target);
        }

        for (int i = start_index; i < nums.size(); i++) {
            if (!visited[i] && current_sum + nums[i] <= target) {
                visited[i] = 1;  // Mark the element as used
                if (solver(nums, visited, i + 1, k, current_sum + nums[i], target)) {
                    return true;
                }
                visited[i] = 0;  // Unmark the element if it doesn't lead to a solution
               if (current_sum == 0)
                    return false;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;  // If the total sum is not divisible by k, return false

        int target = sum / k;
        vector<int> visited(nums.size(), 0);
        sort(nums.begin(), nums.end(), greater<int>());  // Sorting to optimize the backtracking

        return solver(nums, visited, 0, k, 0, target);
    }
};