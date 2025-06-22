class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        vector<string>ans;
        string curr = "";
        for(auto elem : s)
        {
            if(curr.size() == k)
            {
                ans.push_back(curr);
                curr = "";
                curr+=elem;
            }

            else{
                    curr+=elem;
            }
        }

        if(!curr.empty())
        {
            while(curr.size() != k)
            {
                curr+=fill;
            }

            ans.push_back(curr);
        }

        return ans;
    }
};