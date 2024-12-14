class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // Monotonic deque to track maximum and minimum elements
        deque<int> maxQ, minQ;
        int left = 0;
        long long count = 0;

        for (int right = 0; right < nums.size(); right++) {
            // Maintain decreasing monotonic deque for maximum values
            while (!maxQ.empty() && nums[maxQ.back()] < nums[right]) {
                maxQ.pop_back();
            }
            maxQ.push_back(right);

            // Maintain increasing monotonic deque for minimum values
            while (!minQ.empty() && nums[minQ.back()] > nums[right]) {
                minQ.pop_back();
            }
            minQ.push_back(right);

            // Shrink window if max-min difference exceeds 2
            while (!maxQ.empty() && !minQ.empty() &&
                   nums[maxQ.front()] - nums[minQ.front()] > 2) {
                // Move left pointer past the element that breaks the condition
                if (maxQ.front() < minQ.front()) {
                    left = maxQ.front() + 1;
                    maxQ.pop_front();
                } else {
                    left = minQ.front() + 1;
                    minQ.pop_front();
                }
            }

            // Add count of all valid subarrays ending at current right pointer
            count += right - left + 1;
        }
        return count;
    }
};