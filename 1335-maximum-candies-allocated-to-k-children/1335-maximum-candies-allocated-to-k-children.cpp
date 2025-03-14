class Solution {
public:

    long long solver(vector<int>& candies,int mid)
    {
        long long sub =0;
        // cout<<mid;
        for(auto elem : candies)
        {
            sub += (elem/mid);
        }

        return sub;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        
        int start = 1;
        int end = *max_element(candies.begin(),candies.end());
        long long ans =0;

        while(start <= end)
        {
            long long mid = start + (end-start)/2;

            if(solver(candies,mid) >= k)
            {
                ans = mid;
                start = mid + 1;
            }

            else{
                  end = mid - 1;
            }
        }

        return ans;
    }
};