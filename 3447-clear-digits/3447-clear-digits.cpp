class Solution {
public:
    string clearDigits(string s) {
        
        stack<char>st;

        for(auto elem : s)
        {
            if(isdigit(elem))
            {
                st.pop();
            }

            else
            {
                st.push(elem);
            }
        }

        string ans="";

        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());


        return ans;
    }
};