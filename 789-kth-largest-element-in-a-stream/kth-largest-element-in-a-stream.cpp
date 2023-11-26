class KthLargest {
public:
priority_queue<int, vector<int>, greater<>> pq;
int k ;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i =0;i<nums.size();i++)
        {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
       
       if(pq.size()>k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */