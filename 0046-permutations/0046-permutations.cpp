class Solution {
public:

    unordered_set<int>holder;
    int n;

    void solver(vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
        }

        for(int i=0;i<n;i++)
        {
            if(!holder.count(nums[i]))
            {
            temp.push_back(nums[i]);
            holder.insert(nums[i]);
            solver(nums,temp,ans);
            holder.erase(nums[i]);
            temp.pop_back();

            }

        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;

        solver(nums,temp,ans);

        return ans;
        
    }
};