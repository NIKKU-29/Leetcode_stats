class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int>mp;
        int Ecount = n;

        for(auto elem : nums)
        {
            mp[elem]++;
        }

        int count =0;
        
        for(int i = 0 ; i<  n ;i+=3)
        {
            if(mp.size() != Ecount)
            {

                if(Ecount < 3)
                {
                    count++;
                    return count;
                }

                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                mp[nums[i+1]]--;
                if(mp[nums[i+1]]==0) mp.erase(nums[i+1]);
                mp[nums[i+2]]--;
                if(mp[nums[i+2]]==0) mp.erase(nums[i+2]);

                Ecount-=3;
                count++;
            }

            else{
                    return count;
            }
        }


        return count;
    }
};