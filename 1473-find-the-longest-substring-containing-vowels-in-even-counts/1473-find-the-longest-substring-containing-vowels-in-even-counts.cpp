class Solution {
public:
    int findTheLongestSubstring(string s) {

        unordered_map<int,int>mp;

        int bitmask=0; //00000
        
        mp[bitmask]=-1;

        int ans=0;


        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            {
                bitmask= bitmask ^ (1<<0);
            }
            else if(s[i]=='e')
            {
                bitmask= bitmask ^ (1<<1);
            }
            else if(s[i]=='i')
            {
                bitmask= bitmask ^ (1<<2);
            }
            else if(s[i]=='o')
            {
                bitmask= bitmask ^ (1<<3);
            }
            else if(s[i]=='u')
            {
                bitmask= bitmask ^ (1<<4);
            }

        if(mp.find(bitmask)!=mp.end())
        {
            ans=max(ans,i-mp[bitmask]);
        }

        else{

            mp[bitmask]=i;
        }
        }


    return ans;

    }
};