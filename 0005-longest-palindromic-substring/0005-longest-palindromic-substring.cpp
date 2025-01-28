class Solution {
public:

    bool palindrom(int i,int j,string& s)
    {
        if(i>=j) 
        {
            return true;
        }

        if(s[i]==s[j])
        {
            return palindrom(i+1,j-1,s);
        }


        return false;
    }

    string longestPalindrome(string s) {

        int n=s.size();
        int maxL=1;
        int idx=0;

        for(int i=0 ;i< n ;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(palindrom(i,j,s))
                {
                    if(j-i+1 > maxL)
                    {
                        maxL=j-i+1;
                        idx=i;
                    }
                }
            }
        }
        return s.substr(idx,maxL);
    }
};