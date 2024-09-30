class CustomStack {

    deque<int>dq;
    int maxSize;

public:
    CustomStack(int maxSize) : maxSize(maxSize){}
    
    void push(int x) {

        if(dq.size()<maxSize) dq.push_front(x);
        
    }
    
    int pop() {

        if(dq.size()!=0)
        {
            int top=dq.front();
            dq.pop_front();
            return top;
        }

        return -1;
        
    }
    
     void increment(int k, int val) {
        int limit = min(k, (int)dq.size()); 
        for (int i = dq.size()-limit; i < dq.size() ; i++) {        
            dq[i] += val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */