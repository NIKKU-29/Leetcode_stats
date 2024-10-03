class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;

        for(auto elem : nums)
        {
            sum=(sum + elem)%p;
        }
        int target=(sum%p)%p;
        if(target==0) return 0;
        int ans=n;

        int curr=0;

        for(int i=0;i<n;i++)
        {
            curr=(curr + nums[i])%p;
            int aim=( curr - target + p )%p;
                
                if(mp.find(aim)!=mp.end())
                {
                    ans=min(ans,i-mp[aim]);
            }
                    mp[curr]=i;
        }
        
        return ans==n ? -1 : ans;
    }
};