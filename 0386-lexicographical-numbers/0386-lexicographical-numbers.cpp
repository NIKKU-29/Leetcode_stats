class Solution {
public:

    void solver(int curr , int limit, vector<int>&ans)
    {
        if(curr > limit) return;
        ans.push_back(curr);

        for(int i = 0 ; i <= 9 ; i++)
        {
            int next = curr * 10 + i;
            if(next > limit) continue;
            solver(next,limit,ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        
        // vector<int>ans;
        // vector<string>v;
        // for(int i = 1; i <= n ; i++)
        // {
        //     v.push_back(to_string(i));
        // }

        // sort(v.begin(),v.end());

        // for(auto elem : v)
        // {
        //     ans.push_back(stoi(elem));
        // }

        // return ans;

        vector<int>ans;

        for(int i = 1 ; i <= 9; i++)
        {
            solver(i,n,ans);
        }

        return ans;
    }
};