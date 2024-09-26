class MyCalendar {

private: 
            map<int,int>event;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {

        event[start]++;
        event[end]--;

        int current=0;

        for(auto & elem : event)
        {
            current += elem.second;

            if(current > 1)
            {
                event[start]--;
                event[end]++;
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */