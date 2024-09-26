// class MyCalendar {

// private: 
//             map<int,int>event;
// public:
//     MyCalendar() {
        
//     }
    
//     bool book(int start, int end) {

//         event[start]++;
//         event[end]--;

//         int current=0;

//         for(auto & elem : event)
//         {
//             current += elem.second;

//             if(current > 1)
//             {
//                 event[start]--;
//                 event[end]++;
//                 return false;
//             }
//         }
        
//         return true;
//     }
// };

// /**
//  * Your MyCalendar object will be instantiated and called as such:
//  * MyCalendar* obj = new MyCalendar();
//  * bool param_1 = obj->book(start,end);
//  */

class MyCalendar {
    map<int, int> intervals; // Stores intervals with start as key and end as value
public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto next = intervals.lower_bound(start); // Find next interval
        if (next != intervals.end() && next->first < end) {
            return false; // Overlaps with next interval
        }
        if (next != intervals.begin() && prev(next)->second > start) {
            return false; // Overlaps with previous interval
        }
        intervals[start] = end; // No overlap, add interval
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */