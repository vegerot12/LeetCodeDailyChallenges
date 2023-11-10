class Solution {
public:
    int reverse(int x) {
        int cur, rev=0;

        while(x){
            cur = x%10;
            x = x/10;

            if(rev > INT_MAX/10 || rev < INT_MIN/10) return 0;

            if( (rev == INT_MAX/10 and cur > 7 )|| (rev == INT_MIN/10 and cur< -8)) return 0;

            rev = rev*10 + cur;

            
        }
        return rev;
    }
};