class Solution {
public:
    vector<vector<int>>ans;
    int n;


    void solver(unordered_map<int,int>&mp,vector<int>& temp)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }

        for(auto& elem : mp)
        {
            if(elem.second==0)
            {
                continue;
            }

            
                temp.push_back(elem.first);
                mp[elem.first]--;
                solver(mp,temp);
                temp.pop_back();
                mp[elem.first]++;
            
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {

        n=nums.size();
        unordered_map<int,int>mp;

        for(auto elem : nums)
        {
            mp[elem]++;
        }

        vector<int>temp;
        solver(mp,temp);
        
        return ans;
    }
};