class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        

        sort(events.begin(),events.end(),[](const vector<int>&a,const vector<int>&b){

                return (a[1] == b[1]) ? a[0] < b[0] : a[1] < b[1];
        });

        int maxe = 0;
        for(auto elem : events) maxe = max(maxe,elem[1]);
        set<int>s;
        for(int i = 1; i <= maxe ; i++) s.insert(i);
        // vector<int> days(maxe);
        // iota(days.begin(), days.end(), 1); 
        // set<int> s(days.begin(), days.end()); 

        int count = 0;
        for(auto ele : events)
        {
            int start = ele[0];
            int end = ele[1];
            
            auto it = s.lower_bound(start);
            if(it == s.end() || *it > end) continue;
            else count++; s.erase(it);
        }
        
        return count;
    }
};