class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        set<int> s;

        // Sort events by end date first, then by start date
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[1] == b[1]) ? a[0] < b[0] : a[1] < b[1];
             });

        // Find the maximum end date to limit the size of the set
        int maxEnd = 0;
        for (const auto& event : events) {
            maxEnd = max(maxEnd, event[1]);
        }

        // Initialize the set with dates from 1 to maxEnd
        for (int i = 1; i <= maxEnd; i++) {
            s.insert(i);
        }

        int cnt = 0;
        for (const auto& event : events) {
            int start = event[0];
            int end = event[1];

            auto it = s.lower_bound(start);
            if (it == s.end() || *it > end) {
                continue;
            } else {
                cnt++;
                s.erase(it);
            }
        }

        return cnt; // Return the number of days attended
    }
};
