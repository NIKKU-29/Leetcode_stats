class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        int initialday = days,free = 0;
        int prefix =0;
        map<int,int>mp;

        for(auto elem : meetings)
        {
            initialday = min(initialday,elem[0]);

            mp[elem[0]]++;
            mp[elem[1] + 1]--;
        }

        free+=(initialday - 1);

        for(auto day : mp)
        {
            int currday = day.first;

            if(prefix == 0)
            {
                free += (currday - initialday);
            } 

            prefix+=day.second;
            initialday = currday;

        }

        free+= days - initialday + 1;
        return free;
    }
};