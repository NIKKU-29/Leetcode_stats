class Solution {
public:
    int findLHS(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        
        unordered_map<int,int>mp;

        for(auto elem : nums) mp[elem]++;

        for(auto elem : mp)
        {

           if(mp.find(elem.first + 1) != mp.end())
            {
                int count = mp[elem.first + 1];
                ans = max(ans, (mp[elem.first] + count));
            }

        }

        return ans;
    }
};