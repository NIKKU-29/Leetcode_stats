class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n=nums.size();
        // vector<int>vec(1e5);
        unordered_map<long long,long long>mp;

        for(int i=0 ;i<n;i++)
        {
            int newV=nums[i]-i;
            nums[i]=newV;
            mp[newV]++;
        }

        long long count=(n*(n-1)/2);
        long long sum=0;

        for(auto &[key,value] : mp)
        {
           if(value > 1)
           {
                sum+=(value*(value-1)/2);
           }
        }


        return count-sum;
    }
};