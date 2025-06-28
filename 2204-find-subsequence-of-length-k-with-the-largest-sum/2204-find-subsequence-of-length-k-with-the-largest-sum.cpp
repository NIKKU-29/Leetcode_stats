class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<int>proxy = nums;
        sort(proxy.begin(),proxy.end());
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i = n - k ; i < n ; i++)
        {
            mp[proxy[i]]++;
        }

        vector<int>ans;

        for(auto elem : nums)
        {
            if(mp[elem]!=0)
            {
                ans.push_back(elem);
                mp[elem]--;
            }
        }

        return ans;
    }
};