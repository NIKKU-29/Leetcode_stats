class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        int i=0,j=0;
        unordered_map<char,int>mp;
        int ans =0;

        while(j < n )
        {
            mp[s[j]]++;
          

            while(i < n && mp.size() == 3)
            {
                cout<<n-j<<"-<>"<<endl;
                ans+= n - j;
                mp[s[i]]--;
              
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }


            j++;
        }

        return ans;
    }
};