class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        // map<int,int>mp;
        vector<int>mp(1001,0);

        for(auto elem : nums1)
        {
            mp[elem[0]]+=elem[1];
        }

        for(auto elem : nums2)
        {
            mp[elem[0]]+=elem[1];
        }

        vector<vector<int>>ans;

        for(int i=0 ;i<= 1000 ;i++)
        {
            if(mp[i] != 0) ans.push_back({i,mp[i]});
        }

        return ans;
    }
};