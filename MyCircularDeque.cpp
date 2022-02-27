class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        size = k;
    }
    
    bool insertFront(int value) {
        if (d.size() < size) {
            d.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if (d.size() < size) {
            d.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if (d.size() == 0) {
            return false;
        }
        d.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if (d.size() == 0) {
            return false;
        }
        d.pop_back();
        return true;
    }
    
    int getFront() {
        if (d.size() == 0) {
            return -1;
        }
        return d.front();
    }
    
    int getRear() {
        if (d.size() == 0) {
            return -1;
        }
        return d.back();
    }
    
    bool isEmpty() {
        return d.size() == 0;
    }
    
    bool isFull() {
        return d.size() == size;
    }
private:
    deque<int> d;
    int size;
};
