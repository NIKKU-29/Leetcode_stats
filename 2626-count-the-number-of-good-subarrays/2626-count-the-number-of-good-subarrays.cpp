class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        long long count = 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<long long,long long>mp;
        int paircount = 0;

        while(r < n)
        {
            paircount+=mp[nums[r]];
            mp[nums[r]]++;
            

            while(paircount >= k )
            {
                count += n - r;
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                paircount-=mp[nums[l]];
                l++;

            }

            r++;
        }


        return count;

    }
};