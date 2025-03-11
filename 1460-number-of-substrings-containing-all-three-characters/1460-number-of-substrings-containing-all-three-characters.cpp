class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        int i=0,j=0;
        // unordered_map<char,int>mp;
        int a=0,b=0,c=0;
        int ans =0;

        while(j < n )
        {
           if(s[j] == 'a') a++;
           if(s[j] == 'b') b++;
           if(s[j] == 'c') c++;
          

            while(i < n && a>0 && b > 0 && c > 0)
            {
                ans+= n - j;
                if(s[i] == 'a') a--;
                if(s[i] == 'b') b--;
                if(s[i] == 'c') c--;
                i++;
            }


            j++;
        }

        return ans;
    }
};