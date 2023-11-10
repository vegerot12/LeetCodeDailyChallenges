class Solution {
public:
    double getPow(double x, int n){
        if(n == 0) return 1;

        double res = getPow(x,n/2);
        res = res* res;
        return n%2 ? x*res: res;
    }
    double myPow(double x, int n) {
        if (x == 0) return 0;
        auto res = getPow(x,n);
        return n<0 ? 1/res : res;
    }
};
