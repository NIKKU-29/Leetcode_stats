class Solution {
public:
    int minLength(string s) {

        stack<int>st;

        for(auto elem : s)
        {
            if(st.empty())
            {
                st.push(elem);
            }

            else if(st.top() == 'A' && elem == 'B' || st.top() =='C' && elem =='D')
            {
                st.pop();
            }

            else
            {
                st.push(elem);
            }
        }
        
        return st.size();

    }
};