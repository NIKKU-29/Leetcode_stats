class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int n=queries.size();
        vector<int>PreXoR;
        vector<int>ans;
        int XoR=0;

        for(auto elem : arr)
        {   
            XoR^=elem;
            PreXoR.push_back(XoR);
        }

        for(auto elem : queries)
        {
            int start=elem[0];
            int end=elem[1];
            if(start!=0)
            {
            ans.push_back(PreXoR[start-1] ^ PreXoR[end]);
            }
            else{

                ans.push_back(PreXoR[end]);
            }

        
        }

        return ans;
        
    }
};