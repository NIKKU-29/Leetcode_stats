class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long count = 0;
        int n = nums.size();
        int l = 0, r = 0;
        unordered_map<int, int> freq;
        long long pairCount = 0;
        
        while (r < n) {
    
            int oldFreq = freq[nums[r]];
            long long oldPairs = (long long)oldFreq * (oldFreq - 1) / 2;
          
            freq[nums[r]]++;
        
            int newFreq = freq[nums[r]];
            long long newPairs = (long long)newFreq * (newFreq - 1) / 2;
            pairCount += (newPairs - oldPairs);
         
            while (pairCount >= k) 
            {
                
                count += n - r;
           
                oldFreq = freq[nums[l]];
                oldPairs = (long long)oldFreq * (oldFreq - 1) / 2;
              
                freq[nums[l]]--;
                         
                newFreq = freq[nums[l]];
                newPairs = (long long)newFreq * (newFreq - 1) / 2;
              
                pairCount -= (oldPairs - newPairs);
                l++;
            }
            
            r++;
        }
        
        return count;
    }
};