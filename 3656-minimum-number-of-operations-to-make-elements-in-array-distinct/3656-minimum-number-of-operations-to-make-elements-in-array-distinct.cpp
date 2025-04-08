class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        int elemcount=n;
        for(auto elem : nums)
            {mp[elem]++;}


        int count=0; //number of times removing starting 3 is done
        for(int i=0 ; i < n ;i+=3)
            {
                if(mp.size()!=elemcount)
                {
                    if(mp.size() < 3) 
                    {

                        count++;
                        return count;
                    }
                    
                    //remove starting 3
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    mp[nums[i+1]]--;
                    if(mp[nums[i+1]]==0) mp.erase(nums[i+1]);
                    mp[nums[i+2]]--;
                    if(mp[nums[i+2]]==0) mp.erase(nums[i+2]);
                    elemcount-=3;
                    count++;
                }
                    
                else{
                        return count;
                }
            }

        return count;
    }
};