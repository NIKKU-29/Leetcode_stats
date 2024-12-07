class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;

        while(l <= r)
        {
            int mid= l + (r-l)/2;
            int operations=0;

            cout<<mid<<" <-MID";
            for(auto elem : nums)
            {
               operations += (elem -1) / mid  ;
            }

            cout<<"----->"<<operations<<endl;
            

            if(operations <= maxOperations)
            {
                ans=min(mid,ans);
                r=mid-1;
            }

            else{
                    l=mid+1;
            }
        }

        return ans;
    }
};