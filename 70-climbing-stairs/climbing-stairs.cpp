class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
int oneStepAway  = 2, twoStepAway =1, c=0;
      // a is prev and b is cur
      for(int i=3;i<=n;i++){
         c = oneStepAway + twoStepAway;
         twoStepAway = oneStepAway;
         oneStepAway = c;
      }
      return c;

       
        
    }
};

/*
n=5

0 1 2 3 4 5
0 1 2 3 5 8

*/