class MyQueue {
public:
    stack<int> rev, s;

    MyQueue() {
        
    }
    
    void push(int x) {
        
       
        s.push(x);
    }
    
    int pop() {

        int res = peek();
        rev.pop();
        return res;
        
    }
    
    int peek() {
        if(rev.empty()){
        while(!s.empty()){
            int t = s.top();
            s.pop();
            rev.push(t);
        }
        }

        
       
        return rev.top();
    }
    
    bool empty() {
        return rev.empty() && s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */