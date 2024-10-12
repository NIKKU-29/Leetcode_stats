class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        priority_queue<int,vector<int>,greater<int>>occupied;

        sort(intervals.begin(),intervals.end());

        for(auto elem : intervals)
        {
            int start=elem[0];
            int end=elem[1];

            if(!occupied.empty() && occupied.top() < start)
            {
                occupied.pop();
            }

            occupied.push(end);
        }


        return occupied.size();
        
    }
};