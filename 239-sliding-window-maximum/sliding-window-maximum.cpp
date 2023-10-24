class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> res;

        for(int i =0;i<n;i++){
            

      while(!dq.empty() && nums[dq.back()] < nums[i])  {
        //  cout<<dq.back()<<"removed"<<nums[i]<<endl;
         dq.pop_back(); 

     }              
            dq.push_back(i);

            while(!dq.empty() && i-dq.front() >=k){
                dq.pop_front();
            }
            if(i>=k-1 && dq.size()){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};