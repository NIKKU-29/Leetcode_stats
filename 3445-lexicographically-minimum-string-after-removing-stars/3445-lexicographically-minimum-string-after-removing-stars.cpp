class Solution {
public:
    string clearStars(string s) {

        map<char,vector<int>>mp;

        for(int i =0 ; i < s.size() ; i++)
        {
            if(s[i] != '*')
            {
                mp[s[i]].push_back(i);
            }

            else{
                    for(char i = 'a' ; i <= 'z' ; i++)
                    {
                        if(mp.find(i) != mp.end())
                        {
                            mp[i].pop_back();
                            if(mp[i].size() == 0) mp.erase(i);
                            break;
                        }
                    }
            }
        }


        set<int>valid;

        for(auto elem : mp)
        {
            for(auto ele : elem.second)
            {
                valid.insert(ele);
            }
        }

        string ans = "";

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(valid.count(i)) ans+=s[i];
        }


        return ans;
        
    }
};