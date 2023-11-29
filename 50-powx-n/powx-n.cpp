class Solution {
public:
    double pow(double x, int n){
        if(n == 0) return 1;

        double res = pow(x, n/2);
        res = res*res;
        return n%2 ? res * x : res;
    }
    double myPow(double x, int n) {
        if(x==0) return 0;
        double res = pow(x,n);
        return n<0 ? 1/ res : res;
    }
};