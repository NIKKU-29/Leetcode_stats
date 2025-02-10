class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for (char c : s) {
            if (isdigit(c)) {
            
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                
                st.push(c);
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};