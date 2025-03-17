class Solution {
public:
    bool divideArray(vector<int>& nums) {

        vector<int>mp(501,0);

        for(auto elem : nums)
        {
            mp[elem]++;
        }

        for (auto elem : mp) 
        {
            if(elem % 2) return false;
        }

        return true;
    }
};