class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        
        int baseline = max(startTime[0], eventTime - endTime[n - 1]);
        for (int i = 0; i < n - 1; i++) {
            baseline = max(baseline, startTime[i + 1] - endTime[i]);
        }
        
        int result = baseline;
        
        vector<int> gaps(n - 1);
        for (int i = 0; i < n - 1; i++) {
            gaps[i] = startTime[i + 1] - endTime[i];
        }
        
        vector<int> prefixMax(n - 1), suffixMax(n - 1);
        prefixMax[0] = gaps[0];
        for (int i = 1; i < n - 1; i++) {
            prefixMax[i] = max(prefixMax[i - 1], gaps[i]);
        }
        
        suffixMax[n - 2] = gaps[n - 2];
        for (int i = n - 3; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], gaps[i]);
        }
        
        for (int i = 0; i < n; i++) {
            int duration = endTime[i] - startTime[i];
            vector<int> candidates;
            
            if (i == 0) {
                candidates = {startTime[1], eventTime - endTime[n - 1]};
                if (n - 1 >= 2) candidates.push_back(suffixMax[1]);
            } else if (i == n - 1) {
                candidates = {startTime[0], eventTime - endTime[n - 2]};
                if (n - 1 >= 2) candidates.push_back(prefixMax[n - 3]);
            } else {
                candidates = {startTime[0], eventTime - endTime[n - 1]};
                if (i - 2 >= 0) candidates.push_back(prefixMax[i - 2]);
                if (i + 1 <= n - 2) candidates.push_back(suffixMax[i + 1]);
                candidates.push_back(startTime[i + 1] - endTime[i - 1]);
            }
            
            sort(candidates.rbegin(), candidates.rend());
            int maxGap = candidates[0], altGap = candidates.size() > 1 ? candidates[1] : 0;
            
            if (count(candidates.begin(), candidates.end(), maxGap) > 1 || altGap >= duration) {
                result = max(result, maxGap);
            } else {
                result = max(result, maxGap - duration);
            }
        }
        
        return result;
    }
};