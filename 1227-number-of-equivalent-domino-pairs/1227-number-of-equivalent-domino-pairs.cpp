class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        map<pair<int,int>,int>mp;
        int pairs = 0;


        for (auto elem : dominoes)
            {
                int a = elem[0];
                int b = elem[1];

                if (a <= b) mp[{a, b}]++;
                else mp[{b, a}]++;
            }


            for(auto elem : mp)
            {
                int count = elem.second;

                if(count > 1)
                {
                    pairs += (count * (count -1))/2;
                }
            }

        return pairs;
    }
};