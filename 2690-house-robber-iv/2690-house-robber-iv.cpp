class Solution {
public:

    bool valid(vector<int>nums,int mid , int k)
    {   
        int n = nums.size();
        int count=0;
        int i=0;
        while(i < n)
        {
            if(nums[i] <= mid)
            {
                count++;
                if(count >= k) return true;
                i+=2;
            } 

            else{
                    i+=1;
            }  
        }

        
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        
        int SL = *min_element(nums.begin(),nums.end());
        int LL = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(SL <= LL)
        {
            int mid = SL + (LL-SL)/2;
            
            if(valid(nums,mid,k))
            {
                 ans = mid;
                 LL = mid -1;
            }

            else{
                 SL = mid +1;
            }
            
        }

        return ans;
    }
};