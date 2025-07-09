class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
         int n = startTime.size();
      
        vector<int> d(n,0);
        vector<int> P(n+1, 0); 
        for (int i = 0; i < n; i++){
            d[i] = endTime[i] - startTime[i];
            P[i+1] = P[i] + d[i];
        }
 
 
        int baseline = startTime[0]; // gap first
        baseline = max(baseline, eventTime - endTime[n-1]); // gap after last
        for (int i = 0; i < n-1; i++){
            baseline = max(baseline, startTime[i+1] - endTime[i]);
        }
 
        int ans = baseline;
 
        // If k >= n, we can move all meetings.
        if(k >= n){
            ans = max(ans, eventTime - P[n]);
            return ans;
        }
 
 
        // vector<int> X(n,0);
        // for (int j = 0; j < n; j++){
        //     X[j] = startTime[j] - P[j];
        // }
 
        // For i >= 1, define C[i] = P[i] - endTime[i-1].
        vector<int> C(n, 0); // valid for i from 1 to n-1.
        for (int i = 1; i < n; i++){
            C[i] = P[i] - endTime[i-1];
        }
 
        
        int candidate_begin = 0;
        // r can range from 0 to min(n-2, k-1)
        for (int r = 0; r < min(n-1, k); r++){
            int j = r + 1; // fixed meeting index = r+1
            candidate_begin = max(candidate_begin, startTime[j] - P[j]); // = X[j]
        }
 
        // block removed at end.
        // remove meetings [i, n-1] for some i >= 1 with (n - i) <= k.
        int candidate_end = 0;
        for (int i = max(1, n - k); i < n; i++){
            candidate_end = max(candidate_end, eventTime - P[n] + C[i]);
        }
 
        
        int candidate_middle = 0;
       
        deque<int> dq; // will store indices i, in decreasing order of C[i].
        // Iterate j from 2 to n-1.
        for (int j = 2; j < n; j++){
            // Remove indices out of the current window [j - k, j - 1].
            while(!dq.empty() && dq.front() < j - k)
                dq.pop_front();
            int idx = j - 1;
            // Remove from back while C[idx] is larger.
            while(!dq.empty() && C[dq.back()] <= C[idx])
                dq.pop_back();
            dq.push_back(idx);
 
            
            int cur = (startTime[j] - P[j]) + C[dq.front()]; // = X[j] + max C[i]
            candidate_middle = max(candidate_middle, cur);
        }

        ans = max({ans, candidate_begin, candidate_middle, candidate_end});

        cout<<ans;
        return ans;
    }
};