class Solution {
public:
    string longestPrefix(string s) {

        int n=s.size();
        vector<int>KMP(n);
        int i=1;
        int length=0;
        KMP[0]=0;

        while(i < n )
        {
            if(s[length]==s[i])
            {
                length++;
                KMP[i]=length;
                i++;
            }

            else{
                    if(length!=0)
                    {
                        length=KMP[length-1];
                    }

                    else{
                            KMP[i]=0;
                            i++;
                    }
            }
        }

        if(KMP[n-1]==0) return "";

        int len=KMP[n-1];

        return s.substr(n-len,len);
        
    }
};