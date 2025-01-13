class Solution {
public:
    int minimumLength(string s) {

        unordered_map<int,int>mp;

        for(auto elem : s)
        {
            mp[elem]++;
        }

        int count=0;

        for(auto elem : mp)
        {
            if(elem.second >= 3)
            {
                int num=elem.second;

                while(num >= 3)
                {
                    count+=2;
                    num-=2;
                }
            }
        }

        return s.size()-count;   
    }
};