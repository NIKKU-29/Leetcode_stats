class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long count = 0;
        int n = nums.size();
        int l = 0, r = 0;
        unordered_map<int, int> freq;
        long long pairCount = 0;
        
        while (r < n) {
            // Before adding the new element
            int oldFreq = freq[nums[r]];
            long long oldPairs = (long long)oldFreq * (oldFreq - 1) / 2;
            
            // Add the new element
            freq[nums[r]]++;
            
            // After adding the new element
            int newFreq = freq[nums[r]];
            long long newPairs = (long long)newFreq * (newFreq - 1) / 2;
            
            // Update the pair count with the difference
            pairCount += (newPairs - oldPairs);
            
            // Shrink window from left if we have enough pairs
            while (pairCount >= k) {
                // Count all valid subarrays ending at or after r
                count += n - r;
                
                // Before removing the left element
                oldFreq = freq[nums[l]];
                oldPairs = (long long)oldFreq * (oldFreq - 1) / 2;
                
                // Remove the left element
                freq[nums[l]]--;
                
                // After removing the left element
                newFreq = freq[nums[l]];
                newPairs = (long long)newFreq * (newFreq - 1) / 2;
                
                // Update the pair count with the difference
                pairCount -= (oldPairs - newPairs);
                
                l++;
            }
            
            r++;
        }
        
        return count;
    }
};