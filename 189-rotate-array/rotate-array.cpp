class Solution {
public:
/*
nums = [1,2,3,4,5,6,7], k = 3 n=7

1. k = 3%7=3 , start =0, n=7
inner loop k times 

swap nums(start+i) and nums[n-k+start+i] 1234567
swap o to k and n-k to n ----------- IMPORTANT STEP 1
indexes 0 and 7-3+0+0 = 4 sp 1-5  5234167
indexes 1 and 7-3+0+1 = 5 sp 2-6  5634127
indexes 2 and 6 sp 3-7. 5674123


2. n = n-k = 4 k=3 start = start+k = 3
swaps k to k+n and n-k to n 
inner loop k times  start from 3 index.     5674123

swap nums(start+i) and nums[n-k+start+i]
indexes 3 and 4-3+3+0 = 4 sp 4-1 5671423
indexes 4 and 4-3+3+1 = 5 sp 4-2 5671243
indexes 5 and 6 sp 4-3 5671234

2. n = n-k = 1 k=3%1=0  start = start+k = 3
Here k became 0 so we stop , thats why we are keeping k = k%n as judgement for the for loop




Rotating k steps to the right would move the last (n-k) elements to the front, so [6,7,8] are moved to their final position in the 1st iteration.

Now, since [6,7,8] are fixed, we only have to consider about other elements (i.e. [4,5,1,2,3]), that is why (n-=k, nums+=k).
Since we have swapped the first three elements [1,2,3] to the end of the array (It is equal to rotate [1,2,3,4,5] n-k times) in the 1st iteration, we need to rotate it back (i.e. k times) to meet our goal.

Rotating [4,5,1,2,3] to the right k times is a subproblem to the original problem, so the explanation is similar to the above. Just repeat the subproblem until there is no more element to swap.

*/
   
    void rotate(vector<int>& nums, int k) {
               int n= nums.size();
        int start =0;
        //. initially array starts from 0 to n 
        // in every iteration of outer loop we move start to start+k because first k ele are in correct postition
        // outer loop ends if k becomes 0
        // so in every iteration of outerloop n  reduces by k 
        
        // every time n decreases and k at some point may becoem 0 as end the loop 
        for(;  (k>0) ; start=start+k, n=n-k){
           k=k%n;
            for(int i=0;i<k;i++){ // swap first k with last k ele
                swap(nums[start+i], nums[n-k+start+i]);
            }
            
           
        }

        
            
//             
// reverse(nums.begin()+n-(k%n), nums.end());
//   reverse(nums.begin(),nums.begin()+n-(k%n));
//   reverse(nums.begin(),nums.end());
        
      
       
    }
};