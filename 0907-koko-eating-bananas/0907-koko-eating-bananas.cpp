class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = *max_element(piles.begin(),piles.end());
        

        long start=1;
        long end=maxi;

        long ans=maxi;

        while(start<=end)
        {
            long mid=start + (end-start)/2;
            long count=0;

            for(auto elem : piles)
            {
                long quotient=elem / mid;
                long remainder=elem % mid;

                if(remainder>0)
                {
                    count+=quotient + 1;
                }
                else 
                {
                    count+=quotient;
                }
            }

            if(count <= h)
            {
                ans=mid;
                end=mid-1;
            }

            else if(count > h)
            {
                start=mid+1;
            }
        }

        return  (int)ans;
    }
};