class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int i=0;
        int j=0;
        int n=str1.size();
        int m=str2.size();

        if(m>n) return false;

        while(i<n)
        {
            if(str1[i]==str2[j] || ( str1[i]=='z' ? 'a' : str1[i]+1  == str2[j]))
            {
                j++;
                if(j==m) return true;

            }

            i++;

        }


        return false;
        
    }
};