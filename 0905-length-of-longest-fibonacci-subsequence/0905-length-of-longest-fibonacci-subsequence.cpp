class Solution {
public:
    
    int largest=0;

    void solver(int idx,int n,vector<int>&curr,vector<int>&arr,unordered_map<int,int>&mp)
    {
        if(curr.size() >= 3)
        {
             largest = max(largest, (int)curr.size());
        }

        if (idx >= n) {
           
            return;
        }

        int prev2=curr[curr.size() - 2];
        int prev1=curr[curr.size() - 1];
        int sum=prev1+prev2;

        if(mp.find(sum)!=mp.end())
        {
            curr.push_back(sum);
            solver(mp[sum]+1,n,curr,arr,mp);
            curr.pop_back();
        }

       
    }

    int lenLongestFibSubseq(vector<int>& arr) {

            int n=arr.size();
            unordered_map<int,int>mp;
            for(int i=0 ;i< n ;i++) mp[arr[i]]=i;
            

           for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) { 
                vector<int> curr = {arr[i], arr[j]};
                solver(j + 1, n, curr, arr, mp);
            }
        }

            return largest;
    }
};