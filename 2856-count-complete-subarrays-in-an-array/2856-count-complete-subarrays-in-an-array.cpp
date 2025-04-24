class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        int r =0 , l = 0;
        int n = nums.size();
        unordered_map<int,int>mp;

        for(auto elem : nums)
        {
            mp[elem]++;
        }

        unordered_map<int,int>Wmp;
        int count = 0;

        while(r < n)
        {
            Wmp[nums[r]]++;
           
            // cout<<Wmp.size()<<"___"<<mp.size()<<"->"<<r<<endl;

            while(Wmp.size() == mp.size() && l < n)
            {
                count+=(n-r);
                Wmp[nums[l]]--;
                if(Wmp[nums[l]] == 0) Wmp.erase(nums[l]);
                l++;
            }

            r++;
        }
        
        return count;

    }
};