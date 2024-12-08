class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = LLONG_MIN;
        
        // Prefix sum array
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
       
        vector<long long> minPrefixSum(k, LLONG_MAX);
        
      
        for (int i = 0; i <= n; i++) {
            
            if (i >= k) {
                long long subarraySum = prefixSum[i] - minPrefixSum[i % k];
                maxSum = max(maxSum, subarraySum);
            }
           
            minPrefixSum[i % k] = min(minPrefixSum[i % k], prefixSum[i]);
        }

        return maxSum == LLONG_MIN ? -1 : maxSum;
    }
};
