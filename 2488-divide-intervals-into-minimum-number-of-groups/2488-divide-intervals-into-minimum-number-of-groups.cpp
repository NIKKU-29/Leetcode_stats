#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        // Step 1: Sort the intervals by their start times
        std::sort(intervals.begin(), intervals.end());

        // Step 2: Min-heap to keep track of the end times of the groups
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        // Step 3: Iterate over each interval
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // If the heap is not empty and the smallest end time is less than the current start time
            // it means we can reuse that group (extend the end time)
            if (!minHeap.empty() && minHeap.top() < start) {
                minHeap.pop(); // Remove the old end time
            }

            // Push the current interval's end time into the heap
            minHeap.push(end);
        }

        // The size of the heap represents the minimum number of groups needed
        return minHeap.size();
    }
};
