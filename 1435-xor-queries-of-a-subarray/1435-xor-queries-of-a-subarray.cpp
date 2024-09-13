class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int n=queries.size();
        vector<int>ans;

        for(auto elem : queries)
        {
            int start=elem[0];
            int end=elem[1];

            int XoR=0;
            for(int i=start ; i<=end ; i++)
            {
                XoR^=arr[i];
            }

            ans.push_back(XoR);
        }

        return ans;
        
    }
};