class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        unordered_map<int,vector<int>>mp;
        int n = groupSizes.size();

        for(int i = 0 ; i<n ;i++)
        {
            mp[groupSizes[i]].push_back(i);
        }

        vector<vector<int>>ans;

        for(auto elem : mp)
        {
            int size = elem.first;
            vector<int>curr;

            for(int i = 0 ; i<elem.second.size();)
            {
                while(i < elem.second.size() && curr.size() != size)
                {
                    curr.push_back(elem.second[i]);
                    i++;
                }

                ans.push_back(curr);
                curr.clear();
            }

        }

        return ans;
    }
};