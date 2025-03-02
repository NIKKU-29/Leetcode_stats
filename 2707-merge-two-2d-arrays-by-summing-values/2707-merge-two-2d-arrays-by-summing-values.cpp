class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        // map<int,int>mp;
        // vector<int>mp(1001,0);
        // for(auto elem : nums1) mp[elem[0]]+=elem[1]; 
        // for(auto elem : nums2) mp[elem[0]]+=elem[1];
        // vector<vector<int>>ans;
        // for(int i=0 ;i<= 1000 ;i++) if(mp[i] != 0) ans.push_back({i,mp[i]});  
        // return ans;

        int starta=0,startb=0;
        int sizea=nums1.size(),sizeb=nums2.size();
        vector<vector<int>>ans;

        while(starta < sizea && startb < sizeb)
        {
            if(nums1[starta][0] > nums2[startb][0])
            {
                ans.push_back({nums2[startb][0],nums2[startb][1]});
                startb++;
            }

            else if(nums1[starta][0] == nums2[startb][0])
            {
                ans.push_back({nums2[startb][0],nums1[starta][1] + nums2[startb][1]});
                starta++,startb++;
            }

            else{
                    ans.push_back({nums1[starta][0],nums1[starta][1]});
                    starta++;
            }

        }


        while(starta < sizea)
        {
            ans.push_back({nums1[starta][0],nums1[starta][1]});
            starta++;
        }

        while(startb < sizeb)
        {
            ans.push_back({nums2[startb][0],nums2[startb][1]});
            startb++;
        }

        return ans;
    }
};