class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int>ans;
        vector<string>v;
        for(int i = 1; i <= n ; i++)
        {
            v.push_back(to_string(i));
        }

        sort(v.begin(),v.end());

        for(auto elem : v)
        {
            ans.push_back(stoi(elem));
        }

        return ans;
    }
};