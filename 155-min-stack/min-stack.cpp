class MinStack {
public:
    vector<int> s;
    int tp=0;

    MinStack() {
        s.resize(100000);
    }
    
    void push(int val) {
        

         if(tp==0){
            s[tp++] = val;
            s[tp++]=val;
        }
        else{
            int minVal = s[tp-1];
            s[tp++]=val;
            s[tp++] = min(val, minVal);
        }
        
    }
    
    void pop() {
       tp=tp-2;
       
    }
    
    int top() {
        return s[tp-2];
    }
    
    int getMin() {
        return s[tp-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */