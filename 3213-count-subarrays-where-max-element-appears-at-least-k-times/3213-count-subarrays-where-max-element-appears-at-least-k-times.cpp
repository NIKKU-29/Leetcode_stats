class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        int l =0 ,r =0;
        unordered_map<int,int>mp;
        int maxelem = *max_element(nums.begin(),nums.end());


        int maxicount = 0;
        long long ans = 0;

        while(r < n)
        {
            if(nums[r] == maxelem) maxicount++;

            while(l <= r && maxicount == k)
            {
                ans+=(n-r);
                if(nums[l] == maxelem) maxicount--;
                l++;
            }

            r++;
        }
        
        return ans;
    }
};