class FreqStack {
public:
unordered_map<int,int> freq;
unordered_map<int, stack<int>> freqStack;
int maxFreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        freqStack[freq[val]].push(val);
    }
    
    int pop() {
        int top = freqStack[maxFreq].top();
        freqStack[maxFreq].pop();
        if(freqStack[maxFreq].size()==0){
            maxFreq--; // we removed only one so reduced by 1 every time
        }
        freq[top]--;
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */