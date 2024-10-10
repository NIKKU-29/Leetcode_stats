class Solution {
public:

    unordered_set<int>holder;
    int n;

    void solver(vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
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

// class Solution {
// public:

//     int n;
//     vector<vector<int>>ans;


//     void solver(int idx,vector<int>& nums)
//     {
//         if(idx==n)
//         {
//             ans.push_back(nums);
//             return;
//         }

//         for(int i=idx;i<n;i++)
//         {
//             swap(nums[i],nums[idx]);
//             solver(idx+1,nums);
//             swap(nums[idx],nums[i]);
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {

//         n=nums.size();
//         solver(0,nums);

//         return ans;
        
//     }
// };