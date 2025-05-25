class Solution {
public:

    bool ispalind(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }

    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int>mp;
        unordered_map<string,int>selfpalindrom;

        for(auto elem : words)
        {
            if(ispalind(elem))
            {
                selfpalindrom[elem]++;
            }

            else{
                    mp[elem]++;
            }
        }

        int count= 0;

        
        for (auto& [curr, freq] : mp) {
            string rev = curr;
            reverse(rev.begin(), rev.end());

            if (mp.find(rev) != mp.end()) {
                int pairs = min(freq, mp[rev]);
                count += pairs * 4;

                mp[rev] = 0; 
                mp[curr] = 0;
            }
        }

        bool added = false;
        for(auto& [elem , cnt] : selfpalindrom)
        {
            count+=((cnt/2) * 4);
            if(cnt % 2 == 1 && !added)
            {
                count += 2;
                added = true;
            }
        }

        return count;
    }
};