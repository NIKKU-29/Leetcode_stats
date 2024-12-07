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
                //pura kHEL BAS IS CONDITION KA HAI KI
                //Operations ko evenly divide kaise kare taki mimimum
                //divide ho

                // as in [7,17] , maxoperations=2 
                // ans is 7
                // divide happens like
                // [7,  17     ]
                // [7,  14,3   ] -> 1 operation
                // [7,  7,7,3  ] -> 2 operation

                //maximum is 7 
                //initialy i used (elem - mid) -1 ;
                //but i was wrong 

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