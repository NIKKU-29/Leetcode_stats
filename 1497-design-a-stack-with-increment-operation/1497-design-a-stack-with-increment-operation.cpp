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
        int limit = std::min(k, (int)dq.size()); 
        for (int i = (int)dq.size()-limit; i < (int)dq.size() ; i++) {       
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