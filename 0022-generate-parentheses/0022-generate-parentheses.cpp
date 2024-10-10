class Solution {
public:


    bool isvalid(string& current)
    {
        stack<char>st;

        for(auto elem : current)
        {
            if(elem=='(')
            {
                st.push(elem);
            }

            else if(!st.empty() && st.top()=='(' && elem == ')')
            {
                st.pop();
            }

            else{
                return false;
            }

            
        }

        if(st.empty())  return true;

        return false;
    }

    void solver(string curr , int siz , vector<string>&ans)
    {
        if(curr.size()==siz)
        {
            if(isvalid(curr))
            {
                ans.push_back(curr);
            }

            return;
        }

        curr.push_back('(');
        solver(curr,siz,ans);
        curr.pop_back();
        curr.push_back(')');
        solver(curr,siz,ans);
        curr.pop_back();

        
    }

    vector<string> generateParenthesis(int n) {

        string curr="";
        vector<string>ans;
        solver(curr,n*2,ans);
        return ans;
    }
};