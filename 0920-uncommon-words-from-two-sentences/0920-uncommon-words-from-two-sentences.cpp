class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {


        vector<string>vec;
        stringstream ss1(s1);
        stringstream ss2(s2);

        string word="";

        unordered_map<string,int>mp;

        while(ss1 >> word)
        {
            mp[word]++;
        }
        while(ss2 >> word)
        {
            mp[word]++;
        }

        for(auto elem : mp)
        {
            if(elem.second==1)
            {
            vec.push_back(elem.first);
            }
        }
        return vec;
        
    }
};