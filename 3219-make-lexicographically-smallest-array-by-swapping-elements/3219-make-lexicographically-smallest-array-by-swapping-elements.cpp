class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Create pairs of (value, original index)
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < n; i++) {
            indexed_nums.push_back({nums[i], i});
        }
        
        // Sort by value
        sort(indexed_nums.begin(), indexed_nums.end());
        
        // Group numbers based on the difference limit
        vector<vector<pair<int, int>>> groups;
        
        for (auto& curr : indexed_nums) {
            // If no groups exist or difference exceeds limit, create a new group
            if (groups.empty() || 
                abs(curr.first - groups.back().back().first) > limit) {
                groups.push_back({curr});
            } else {
                // Add to the last group
                groups.back().push_back(curr);
            }
        }
        
        // Result array to store the lexicographically smallest array
        vector<int> ans(n);
        
        // Process each group
        for (auto& group : groups) {
            // Sort original indices within the group
            vector<int> original_indices;
            vector<int> group_values;
            
            for (auto& item : group) {
                original_indices.push_back(item.second);
                group_values.push_back(item.first);
            }
            
            // Sort original indices
            sort(original_indices.begin(), original_indices.end());
            
            // Sort group values
            sort(group_values.begin(), group_values.end());
            
            // Place values in original indices
            for (int i = 0; i < group.size(); i++) {
                ans[original_indices[i]] = group_values[i];
            }
        }
        
        return ans;
    }
};