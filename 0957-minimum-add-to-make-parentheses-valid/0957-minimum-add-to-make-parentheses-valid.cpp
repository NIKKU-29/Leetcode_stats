class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char>st;

        for(auto elem : s)
        {
            if(st.empty())
            {
                st.push(elem);
            }

            else{

                    if(st.top()=='(' && elem == ')')
                    {
                        st.pop();
                    }

                    else{

                        st.push(elem);
                    }

            }
        }

        return st.size();
    }
};