class Solution {
public:
    int climbStairs(int n) {
        // if(n<=2) return n;
int a  = 1, b=1, c=0;
      // a is prev and b is cur
      for(int i=2;i<=n;i++){
         c = b;
         b = a+b;
         a=c;
      }
      return b;

       
        
    }
};