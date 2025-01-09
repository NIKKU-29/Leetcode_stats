class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int n=pref.size();
        int count=0;
        for(auto elem : words)
        {
            count+= (elem.substr(0,n)==pref) ? 1: 0;
        }
        return count;
    }
};