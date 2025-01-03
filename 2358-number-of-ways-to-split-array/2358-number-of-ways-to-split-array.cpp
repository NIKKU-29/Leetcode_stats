class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        vector<long long>presum;
        long long sum=0;

        for(auto elem : nums)
        {
            sum+=elem;
            presum.push_back(sum);
        }

        int count=0;

        for(int i=0 ; i< nums.size()-1 ;i++)
        {

            long long  sum1=presum[i];
            long long sum2=presum[nums.size() -1]-sum1;

            if(sum1 >= sum2)
            {
                count++;
            }

        }

        return count;
    }
};