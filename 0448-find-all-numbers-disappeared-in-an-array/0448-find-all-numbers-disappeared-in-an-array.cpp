class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int maxi=nums.size();
        vector<int>vec(maxi+1,0);

        for(auto elem : nums)
        {
            vec[elem]++;
        }

        int n=vec.size();
        vector<int>ans;

        for(int i=1 ; i<n ; i++)
        {
            if(vec[i]==0) ans.push_back(i);
        }
        

        return ans;
    }
};