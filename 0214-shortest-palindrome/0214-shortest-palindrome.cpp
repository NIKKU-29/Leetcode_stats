class Solution {
public:
    string shortestPalindrome(string s) {

        string compare=s;
        int n=s.size();
        if(n==0) return s;
        reverse(compare.begin(),compare.end());
        string prefix="";


        for(int i=0;i<n;i++)
        {
            if(!memcmp(s.c_str(),compare.c_str()+i,n-i))
            {
                prefix=compare.substr(0,i);
                break;
            }
        }


        return prefix + s;        
    }
};