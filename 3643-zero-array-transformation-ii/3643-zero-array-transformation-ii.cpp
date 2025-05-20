class Solution {
public:

    int solver(vector<int>& nums, vector<vector<int>>& queries,int turns)
    {
        int n = nums.size();
        vector<int>diffarray(n+1,0);

        for(int i = 0 ; i < turns ; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int value = queries[i][2];

            diffarray[start]+=value;
            diffarray[end + 1]-=value;

        }

        long long sum = 0;
        vector<int>presum;

        for(auto elem : diffarray)
        {
            sum+=elem;
            presum.push_back(sum);
        }

        for(int i = 0 ; i < n ; i++)
        {
            if(presum[i] < nums[i])
            {
               return false;
            }
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = queries.size();
        if (accumulate(nums.begin(), nums.end(), 0LL) == 0) return 0;

        int l = 0;
        int r = n;
        int ans = -1;

        while(l <= r)
        {
            int mid = l + (r - l)/2;


            if(solver(nums,queries,mid))
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