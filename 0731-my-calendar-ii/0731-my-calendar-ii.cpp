class MyCalendarTwo {

    private: map<int,int>mp;

public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {

        mp[start]++;
        mp[end]--;

        int active_count=0;

        for(const auto& elem : mp)
        {
            active_count+=elem.second;

            if(active_count > 2)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */