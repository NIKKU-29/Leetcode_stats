class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mini;
        int ans = INT_MAX;

        
        for (auto elem : timePoints) {
            string first = elem.substr(0, 2); //for hours
            string second = elem.substr(3, 2); //for minutes
            mini.push_back(stoi(first) * 60 + stoi(second));  
        }

        sort(mini.begin(), mini.end());

        int n = mini.size();
        
        
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, mini[i + 1] - mini[i]);
        }
        ans = min(ans, (1440 - mini[n - 1] + mini[0]));

        return ans;
    }
};
