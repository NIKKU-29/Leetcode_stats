class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        map<int,int>mp;
        int i = 0; 
        int j = 0;
        int sum = 0;
        int ans = INT_MIN;

        while(j < nums.size())
        {
            sum+=nums[j];
            mp[nums[j]]++;
            while(mp[nums[j]] > 1 && i < j)
                {
                    mp[nums[i]]--;
                    sum-=nums[i];
                    i++;
                }

                ans = max(ans,sum);
            

            j++;
        }
        
        return ans;
    }
};