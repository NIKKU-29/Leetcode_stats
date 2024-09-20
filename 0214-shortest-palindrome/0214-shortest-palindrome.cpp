class Solution {
public:
    string shortestPalindrome(string s) {

        string rev=s;
        int n=s.size();
        if(n==0) return s;
        reverse(rev.begin(),rev.end());

        string lps= s + "&" + rev;

        vector<int>LPS;
        LPS.resize(lps.size());
        int length=0;
        LPS[0]=0;
        int i=1;

        while(i<lps.size())
        {
            if(lps[length]==lps[i])
            {
                length++;
                LPS[i]=length;
                i++;
            }

            else{
                    if(length!=0)
                    {
                        length=LPS[length-1];
                    }

                    else{
                        LPS[i]=0;
                        i++;
                    }
            }
        } 
  


         return rev.substr(0,n-LPS[lps.size()-1]) + s;
    }
};