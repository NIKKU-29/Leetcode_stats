class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n=nums.size();
        int i=n-1;
        int count=0;
        sort(nums.begin(),nums.end());

        while(i>1)
        {
            int start=0;
            int end=i-1;

            while(start < end)
            {


            if(nums[start]+nums[end] > nums[i])
            {
                count+=(end-start);
                end--;
            }

            else{
                start++;
            }
        }

        i--;
    }

    return count;

    }
};