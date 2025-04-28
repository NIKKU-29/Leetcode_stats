class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        long long sum = 0;
        int i = 0;
        
        for(int j = 0; j < n; j++) {
            sum += nums[j];
            
            // While current window is invalid
            while(sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            
            ans += (j - i + 1);
        }
        
        return ans;
    }
};
