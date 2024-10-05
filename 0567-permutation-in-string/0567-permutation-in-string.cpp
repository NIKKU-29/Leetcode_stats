class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s2.size();
        int m = s1.size();

        if (m > n) return false;

        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(auto elem : s1)
        {
            mp1[elem]++;
        }

        
        for(int i=0;i<n;i++)
        {
            mp2[s2[i]]++;

            if(i>=m)
            {
                
                mp2[s2[i-m]]--;

                if(mp2[s2[i-m]]==0)
                {
                    mp2.erase(s2[i-m]);
                }

            }
                if(mp2==mp1)
                {
                    return true;
                }
        }

        return false;
    }
};