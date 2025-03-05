class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),[](const string&  a,const  string& b)
        {
             return a.size() < b.size();
        });

        unordered_map<string,int>mp;
        int maxi=0;

        for(auto word : words)
        {
            mp[word]=1;
            int n=word.size();

            for(int i=0 ;i< n ;i++)
            {
                string prev = word.substr(0,i) + word.substr(i+1,n-1);
                if(mp.find(prev)!=mp.end())
                {
                    mp[word] = max(mp[word],mp[prev]+1);
                }
            }

            maxi=max(maxi,mp[word]);
        }

        return maxi;
    }
};