class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int ans=0;

        if(n2%2==1 || n2==1)
        {
            for(auto elem : nums1)
            {
                ans^=elem;
            }

        }

        if(n1%2==1 || n1==1)
        {

        for(auto elem : nums2)
        {
            ans^=elem;
        }

        }

        return ans;

    }
};