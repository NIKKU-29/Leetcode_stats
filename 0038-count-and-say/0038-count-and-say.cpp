class Solution {
public:

    void solver(int idx,string& curr,string& ans,int& prev,int& count)
    {
        if(idx == curr.size()) 
        {
            ans+=to_string(count);
            ans+= to_string(prev);
            return;
        }

        int digit = curr[idx] - '0';
        if (prev == -1 || prev == digit)
        {
            count++;
            prev = digit;
            solver(idx+1,curr,ans,prev,count);   
        }

        else{  
               int digit = curr[idx] - '0';
                ans += to_string(count);
                ans += to_string(prev);
                count = 1;
                prev = digit;
                solver(idx + 1, curr, ans, prev, count);
        }
    }

    string countAndSay(int n) {

        string curr = "1";
        string ans = "";
        
        if(n == 1) return curr;

        for(int i = 1 ; i < n ; i++)
        {
            int prev = -1;  
            int count = 0;
            ans= "";
            solver(0,curr,ans,prev,count); 
            curr = ans;
        }
        return ans;
    }
};