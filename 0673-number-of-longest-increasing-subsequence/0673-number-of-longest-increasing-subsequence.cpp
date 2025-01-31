class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1);  // LIS length ending at i
        vector<int> count(n, 1);   // Number of LIS ending at i
        
        int max_length = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        // Found a longer subsequence
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    } else if (length[j] + 1 == length[i]) {
                        // Accumulate counts for same-length subsequences
                        count[i] += count[j];
                    }
                }
            }
            max_length = max(max_length, length[i]);
        }
        
        // Sum counts of all LIS with max_length
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (length[i] == max_length) {
                result += count[i];
            }
        }
        return result;
    }
};