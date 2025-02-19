class Solution {
public:

    void solver(string &curr,vector<char>&vec,vector<string>&ans,int n)
    {
        if(curr.size() >= n)
        {
            ans.push_back(curr);
            return;
        }

            for(int i=0 ;i<3 ;i++)
            {
                if(vec[i]!=curr.back())
                {
                    curr+=vec[i];
                    solver(curr,vec,ans,n);
                    curr.pop_back();
                }
            }

            return;
    }

    string getHappyString(int n, int k) {
        vector<char>vec={'a','b','c'};
        string curr="";
        vector<string>ans;

        for(int i=0 ;i<3;i++)
        {
            curr+=vec[i];
            solver(curr,vec,ans,n);
            curr.pop_back();
            
        }

        if(k > ans.size()) return ""; 
        return ans[k-1];
    }
};