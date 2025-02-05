class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        int deafulter=0;

        for(int  i=0 ;i< s1.size() ;i++)
        {
            mp1[s1[i]]++;
            mp2[s2[i]]++;

            if(s1[i]!=s2[i])
            {
                deafulter++;
            }
        }

            if(mp1!=mp2) return false;

            if(deafulter == 1 || deafulter >=3) return false;

        return true;
    }
};