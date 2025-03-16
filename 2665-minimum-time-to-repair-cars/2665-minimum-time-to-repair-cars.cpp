class Solution {
public:

    long long solver(long long time ,vector<int>& ranks)
    {
        long long ans =0;

        for(auto elem : ranks)
        {
            ans += floor(sqrt(time/elem));
        }

        return ans;
    }

    long long repairCars(vector<int>& ranks, long long cars) {
        
        int n = ranks.size();
        long long l = 1;
        long long r = 100 * cars * cars;
        
        long long ans = r;
        while( l <= r)
        {
            long long mid = l + (r - l)/2;

            if( solver(mid,ranks) >= cars)
            {
                ans = mid;
                r = mid - 1;
            }

            else{
                    l = mid + 1;
            }
        }

        return ans;
    }
};