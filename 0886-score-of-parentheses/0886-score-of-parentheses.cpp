class Solution {
public:

    int solve(string &s,int &idx)
    {
        int ans=0;
        while(idx<s.size()&& s[idx]=='(')
        {
            idx++;
            if(s[idx]==')') ans+=1;
            else{
                    ans+=2*solve(s,idx);  
            }

            idx++;
        }

        return ans;
    }

    int scoreOfParentheses(string s) {
        int i=0;
        return solve(s,i);
    }
};