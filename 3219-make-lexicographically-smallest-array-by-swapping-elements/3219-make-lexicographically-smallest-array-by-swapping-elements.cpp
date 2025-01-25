class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        vector<int>vec=nums;
        sort(vec.begin(),vec.end());
        int grpnum=0;

        //this map stores which numis in whch group like 1 is in 0 3 is in 0 and 5 is in 0
        //-------------------------------------------------------------
        // as 1,3,5 have abs diff smaller than limit (group 0)
        //-------------------------------------------------------------
        // as 8,9 hasve abs also smaller than 0 but cant be in grp 0 as both them have 
        // abs diff > limit from all the elements in group 0
        //-------------------------------------------------------------

        unordered_map<int,int>groups;
        groups[vec[0]]=grpnum;

        //now a map is needed which contains all the elemnt sin a smae gorp like 0 has
        // group 0 -> 1,3,5
        // group 1 -> 8,9

        unordered_map<int,deque<int>>GroupMembers;
        GroupMembers[grpnum].push_back(vec[0]);



        for(int i=1 ;i <  nums.size() ;i++)
        {
            if(abs(vec[i]-vec[i-1]) > limit)
            {
                grpnum++; //array is sorted when condition occurs other grp starts now diff>limit
            }

            groups[vec[i]]=grpnum;
            GroupMembers[grpnum].push_back(vec[i]);   
        }

        vector<int>ans(nums.size());
        for(int i=0 ;i< nums.size() ;i++)
        {
            int num=nums[i];
            int groupNumber=groups[num];
            ans[i]=GroupMembers[groupNumber].front();
            GroupMembers[groupNumber].pop_front();
        }


        return ans;
        
    }
};