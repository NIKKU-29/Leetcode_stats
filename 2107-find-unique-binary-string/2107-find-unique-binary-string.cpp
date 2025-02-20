class Solution {
public:

    void solver(int n,string& curr,string& ans,unordered_set<string>&st)
    {
        if(curr.size() == n)
        {
            if(!st.count(curr))
            {
                ans=curr;
            }

            return;
        }

        curr+='1';
        solver(n,curr,ans,st);
        curr.pop_back();
        curr+='0';
        solver(n,curr,ans,st);
        curr.pop_back();
        if(!ans.empty()) return;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
        int n=nums.size();
        string curr="";
        string ans="";

        for(auto elem : nums)
        {
            st.insert(elem);
        }

        solver(n,curr,ans,st);

        return ans;
    }
};