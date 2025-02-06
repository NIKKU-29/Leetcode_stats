class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // 1 tupple contribute to ->>8
        //ab cd -> ab dc -> ba cd -> ba dc
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto i=0 ;i <n-1 ; i++)
       {
            for(auto j=i+1 ; j < n ; j++)
            {
                int a=nums[i];
                int b=nums[j];
                mp[a*b]++;
            }
       }

       int count=0;

       for(auto &[key,value] : mp)
       {
            if( value > 1)
            {
                int times= (value * (value -1))/2;
                count+=(8*times);
            }
       }

       return count;

    }
};