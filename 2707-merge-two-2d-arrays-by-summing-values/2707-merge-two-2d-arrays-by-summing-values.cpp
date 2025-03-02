class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        map<int,int>mp;

        for(auto elem : nums1)
        {
            mp[elem[0]]=elem[1];
        }

        for(auto elem : nums2)
        {
            if(mp.find(elem[0])!=mp.end())
            {
                mp[elem[0]]+=elem[1];
            }

            else{
                    mp[elem[0]]=elem[1]; 
              }
            
        }

        vector<vector<int>>ans;

        for(auto elem : mp)
        {
            ans.push_back({elem.first,elem.second});
        }

        return ans;
    }
};