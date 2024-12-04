class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        //o(n) space and o(n) time
        // int maxi=nums.size();
        // vector<int>vec(maxi+1,0);

        // for(auto elem : nums)
        // {
        //     vec[elem]++;
        // }

        // int n=vec.size();
        // vector<int>ans;

        // for(int i=1 ; i<n ; i++)
        // {
        //     if(vec[i]==0) ans.push_back(i);
        // }
        

        // return ans;

        //o(1) space o(n) time
        int n=nums.size();
        for(int i=0 ; i < n ; i++)
        {
            int index=abs(nums[i])-1;

            if(nums[index]>0)
            {
                nums[index]=-nums[index];
            }
        } 


        vector<int>ans;
        for(int i=0 ; i< n ;i++)
        {
            if(nums[i]>0) ans.push_back(i+1);
        }

        return ans;


    }
};