class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int>vec=arr;
        unordered_map<int,int>mp;
        vector<int>ans;

        sort(vec.begin(),vec.end());
        auto last = unique(vec.begin(),vec.end());
        vec.erase(last,vec.end());
        
        for(int i=0;i<vec.size();i++)
        {
            mp[vec[i]]=i+1;
        }

        for(auto elem : arr)
        {
            ans.push_back(mp[elem]);
        }

        return ans;
    }
};