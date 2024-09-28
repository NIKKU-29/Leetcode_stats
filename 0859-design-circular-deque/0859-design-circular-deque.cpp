class MyCircularDeque {
    vector<int> deq;
    int start, end, count, size;

public:
    MyCircularDeque(int k) {
        deq.resize(k);  
        start = 0;
        end = k - 1;
        count = 0;
        size = k;
    }

    bool insertFront(int value) {
        if (!isFull()) {
            start = (start - 1 + size) % size; // Circular decrement
            deq[start] = value;
            count++;
            return true;
        }
        return false;
    }

    bool insertLast(int value) {
        if (!isFull()) {
            end = (end + 1) % size; // Circular increment
            deq[end] = value;
            count++;
            return true;
        }
        return false;
    }

    bool deleteFront() {
        if (!isEmpty()) {
            start = (start + 1) % size; // Circular increment
            count--;
            return true;
        }
        return false;
    }

    bool deleteLast() {
        if (!isEmpty()) {
            end = (end - 1 + size) % size; // Circular decrement
            count--;
            return true;
        }
        return false;
    }

    int getFront() {
        if (!isEmpty()) {
            return deq[start];
        }
        return -1;
    }

    int getRear() {
        if (!isEmpty()) {
            return deq[end];
        }
        return -1;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};
