class Solution {
public:
    typedef pair<long, long> P;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        // Priority queue for {end time, room number}, to track when rooms are available
        priority_queue<P, vector<P>, greater<P>> pq;

        // Priority queue for available rooms (min-heap based on room numbers)
        priority_queue<int, vector<int>, greater<int>> available;

        // Map to store the count of meetings in each room
        map<int, int> room_counts;

        // Initialize available rooms (0 to n-1)
        for (int i = 0; i < n; i++) {
            available.push(i);
            room_counts[i] = 0;  // Initialize room counts to 0
        }

        // Sort meetings based on start time to process them in order
        sort(meetings.begin(), meetings.end());

        // Process each meeting
        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            int duration = end - start;

            // Free up all rooms whose meetings have ended before the current start time
            while (!pq.empty() && pq.top().first <= start) {
                available.push(pq.top().second);
                pq.pop();
            }

            if (!available.empty()) {
                // If a room is available, assign the meeting to the earliest room
                int room_to_use = available.top();
                available.pop();
                pq.push({end, room_to_use}); // Schedule meeting to end at 'end'
                room_counts[room_to_use]++;  // Increment the count for this room
            } else {
                // No room is available at start time, so delay the meeting
                auto next_free = pq.top();
                pq.pop();
                int room_to_use = next_free.second;
                long new_end_time = next_free.first + duration;  // Delay the meeting
                pq.push({new_end_time, room_to_use});
                room_counts[room_to_use]++;  // Increment the count for this room
            }
        }

        // Find the room that hosted the most meetings
        int most_meetings = -1;
        int max_meeting_count = 0;

        for (const auto& elem : room_counts) {
            if (elem.second > max_meeting_count) {
                max_meeting_count = elem.second;
                most_meetings = elem.first;
            } else if (elem.second == max_meeting_count && elem.first < most_meetings) {
                most_meetings = elem.first;
            }
        }

        return most_meetings;
    }
};
