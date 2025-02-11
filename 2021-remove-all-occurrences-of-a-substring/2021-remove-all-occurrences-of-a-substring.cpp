class Solution {
public:
    string removeOccurrences(string s, string part) {


        int n=part.size();
        string ans="";

        for(auto elem: s){

            ans.push_back(elem);

            if(ans.size() >= n && ans.substr(ans.size()-n) == part)
            {
                ans.erase(ans.size()-n);
            }

        }

        return ans;
        
    }
};