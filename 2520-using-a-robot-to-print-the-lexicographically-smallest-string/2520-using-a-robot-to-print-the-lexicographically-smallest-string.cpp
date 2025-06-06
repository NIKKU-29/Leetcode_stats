class Solution {
public:
    string robotWithString(string s) {
        
        unordered_map<char,int>mp;

        for(auto elem : s)
        {
            mp[elem]++;
        }


        stack<char>st;
        string ans = "";
        char mini = 'a';
        
        for(auto elem : s)
        {
            st.push(elem);
            mp[elem]--;

            while(mini != 'z' && mp[mini] == 0)
            {
                mini++;
            }

            while(!st.empty() && st.top() <= mini)
            {
                ans+=st.top();
                st.pop();
            }
        }

        return ans;
    }
};