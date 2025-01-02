class Solution {
public:

    int t[20001][4];
    int helper(vector<int>&windowSum,int idx, int count , int k)
    {
        if(count==0)
        {
            return 0;
        }

        if(idx>=windowSum.size())
        {
            return INT_MIN;
        }

        if(t[idx][count]!=-1)
        {
            return t[idx][count];
        }



        int take= windowSum[idx] + helper(windowSum,idx+k,count-1,k);
        int notake=helper(windowSum,idx+1,count,k);

        return t[idx][count]=max(take,notake);
    }

    void solve(vector<int>&windowSum,int count , int idx,vector<int>& nums, int k,vector<int>&ans)
    {
        if(count==0) return;

        if(idx >= windowSum.size())
        {
            return;
        }

        int take = windowSum[idx] + helper(windowSum,idx+k,count-1,k);
        int notake = helper(windowSum,idx+1,count,k);


        if(take >= notake)
        {
            ans.push_back(idx);
            solve(windowSum,count-1,idx+k,nums,k,ans);
        }

        else{
            solve(windowSum,count,idx+1,nums,k,ans);
        }   
    }


    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        memset(t , -1, sizeof(t));
        vector<int>windowSum;
        int i=0;
        int j=0;
        int sum=0;

        while(j < nums.size())
        {
            sum+=nums[j];

            if(j-i+1 == k)
            {
                windowSum.push_back(sum);
                sum-=nums[i];
                i++;
            }

            j++;
        }

        vector<int>ans;
        solve(windowSum,3,0,nums,k,ans);
        return ans;

        
    }
};