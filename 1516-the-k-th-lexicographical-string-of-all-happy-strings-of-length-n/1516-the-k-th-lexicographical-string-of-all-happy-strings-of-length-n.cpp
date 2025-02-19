class Solution {
public:

    void solver(string &curr,vector<char>&vec,string&ans,int n,int& k)
    {
        if(curr.size() == n)
        {
            k--;

            if(k==0)
            {
                ans=curr;
            } 
            
            return;
        }

            for(int i=0 ;i<3 ;i++)
            {
                if(vec[i]!=curr.back())
                {
                    curr+=vec[i];
                    solver(curr,vec,ans,n,k);
                    curr.pop_back();
                }
            }

            return;
    }

    string getHappyString(int n, int k) {
        vector<char>vec={'a','b','c'};
        string curr="",ans="";

        for(int i=0 ;i<3;i++)
        {
            curr+=vec[i];
            solver(curr,vec,ans,n,k);
            curr.pop_back();
            
        }
        if (!ans.empty()) return ans;
        return "";
    }
};