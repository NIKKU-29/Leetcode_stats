class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

            int n=arr.size();
            unordered_map<int,int>mp;
            for(int i=0 ;i< n ;i++) mp[arr[i]]=i;


            vector<vector<int>>dp(n,vector<int>(n,2));
            int maxans=0;


            for(int j=1 ;j<n;j++)
            {
                for(int i=0;i<j;i++)
                {
                    int value= arr[j] - arr[i];

                    if(value <arr[i] && mp.find(value)!=mp.end())
                    {
                        int k=mp[value];
                        if(k < i)
                        {
                            dp[i][j]=dp[k][i] + 1;
                            maxans=max(maxans,dp[i][j]);
                        }
                    }
                }
            }

            return maxans >= 3 ? maxans : 0;


    }
};


// class Solution {
// public:
    
//     int largest=0;

//     void solver(int idx,int n,vector<int>&curr,vector<int>&arr,unordered_map<int,int>&mp)
//     {
//         if(curr.size() >= 3)
//         {
//              largest = max(largest, (int)curr.size());
//         }

//         int prev2=curr[curr.size() - 2];
//         int prev1=curr[curr.size() - 1];
//         int sum=prev1+prev2;

//         if(mp.find(sum)!=mp.end())
//         {
//             curr.push_back(sum);
//             solver(mp[sum]+1,n,curr,arr,mp);
//             curr.pop_back();
//         }

//         else{

//             return;
//         }

//     }

//     int lenLongestFibSubseq(vector<int>& arr) {

//             int n=arr.size();
//             unordered_map<int,int>mp;
//             for(int i=0 ;i< n ;i++) mp[arr[i]]=i;
            

//            for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) { 
//                 vector<int> curr = {arr[i], arr[j]};
//                 solver(j + 1, n, curr, arr, mp);
//             }
//         }

//             return largest;
//     }
// };