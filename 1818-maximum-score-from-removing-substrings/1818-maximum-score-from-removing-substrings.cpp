class Solution {
public:

    int sum(string &s ,int money , string find)
    {
        stack<char>st;
        int sum = 0;
        
        for(auto elem : s)
        {
            
            if(!st.empty() && elem == find[1] && st.top() == find[0])
            {
                 st.pop();
                 sum+=money;
            }
            else st.push(elem);
        }

        s="";
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }

        reverse(s.begin(),s.end());

        return sum;
    }

    int maximumGain(string s, int x, int y) {
        
        int ans = 0;
        if(x > y) ans += sum(s,x,"ab") + sum(s,y,"ba");
        else ans += sum(s,y,"ba") + sum(s,x,"ab");

        return ans; 

    }
};