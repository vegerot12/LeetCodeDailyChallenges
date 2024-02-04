class Solution {
public:
    /*
         left[i] the distance between element A[i] and its PLE.
       right[i] the distance between element A[i] and its NLE.

        The final answer is,
        sum(A[i]*left[i]*right[i] )    
    
        
        to handle duplicates -we  Set strict less and non-strict less(less than or equal to) for finding NLE and PLE respectively. The order doesn't matter.

        For example, the below code for finding NLE is strict less, while PLE is actually non-strict less.
        Remark: Although in both loop conditions the signs are set as >, for NLE, we make records inside the loop, while for PLE, records are done outside the loop.

    */
        
    int sumSubarrayMins(vector<int>& nums) {
        
        int n = nums.size();
        int MOD = 1e9 + 7;
        vector<int> left(n), right(n);
        int  res = 0;
        // left to right , find the prev least ele of all

        stack<int> s;
        s.push(0) ; // initilise first index in stack 
        left[0] = 1; // we put 1 because we dont want 0 , so we kind of imagine a -1 is outside before arr so when
        // there are no prev ele we put the dist as i+1 
       for(int i =1;i<nums.size();i++){

           while(!s.empty() && nums[i] < nums[s.top()]){
               s.pop();
           }

           if(s.empty())
           left[i] = i+1;
           else
           left[i] = i - s.top();

           s.push(i);

       }

        while(!s.empty()){
            s.pop();
        }

       s.push(n-1);
        right[n-1] = 1;

       for(int i =n-2;i>=0;i--){

           while(!s.empty() && nums[i] <= nums[s.top()]){
               s.pop();
           }

           if(s.empty())
           right[i] = n-i;
           else
           right[i] = s.top()-i;
           s.push(i);

       }
    

    for(int i =0;i<n;i++){
        long long prod = (left[i] * right[i])%MOD;
        prod = (prod * nums[i])%MOD;
        res = (res + prod)% MOD;

    }
    return res;
    }
};