class Solution {
public:
    int countPalindromicSubsequence(string s) {

        vector<int>left(26,-1);
        vector<int>right(26,-1);
        set<pair<char,char>>st;  //stores the visited start and mid element of string
        

        for(int i=0 ; i< s.size();i++)
        {
            if(left[s[i]-'a']==-1) left[s[i]-'a']=i;
            right[s[i]-'a']=i;
        }


        for(int c=0 ; c < 26 ; c++)
        {
            if(left[c]!=-1 && right[c]!=-1 && left[c]<right[c])
            {
                for(int i=left[c]+1 ; i< right[c] ; i++)
                {
                    st.insert({c+'a',s[i]});
                }
            }
        }

        return st.size();
    }
};