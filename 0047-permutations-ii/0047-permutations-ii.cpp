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

        for(auto& [nums,count] : mp)
        {
            if(count==0)
            {
                continue;
            }

            
                temp.push_back(nums);
                mp[nums]--;
                solver(mp,temp);
                temp.pop_back();
                mp[nums]++;
            
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