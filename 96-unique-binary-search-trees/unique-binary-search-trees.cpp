class Solution {
public:

/*
Approach 1: classical dynamic programming way with O(n^2) and O(n) space
Approach 2 : catalon number formula - O(N)  to evaluate all factorials, space complexity is O(1).
*/
    int numTreesDP(int tot) {
        // DP
        // if n = 4 
        /*
        if we consider 1st node as root then we have 0 nodes in left and 3 in right 
                left.  * right
        total = num[0] * num[3] + // if 1st node root
                num[1] * num[2] + // if 2nd node root
                num[2] * num[1] + // if 3rd node root
                num[3] * num[0] + // if 4th node root
        */

        vector<int> num(tot+1);
        num[0] = num[1] = 1;
        int total, left, right;

        for(int n =2;n<=tot ;n++){ // total npdes fpr each num of npdes
            total = 0;
            for(int curRoot = 1; curRoot<=n ;curRoot++) // consider j th node as root
            {
                left = curRoot-1; //  cur root - 1 
                right = n-curRoot; // num of nodes - cur root node -1
                total+= num[left] * num[right];
            }
            num[n] = total;
        }
        return num[tot];
    }

// C(5,3) = 5/1 * 4/2 * 3/3
        long Binomial(int n,int k){
            k = min(k,n-k);
            long long res = 1;

            for(int i=0;i<k;i++){
                res*= (n-i); // 5-0 . 5-1 . 5-2
                res/= i+1; // 0+1. 1+1. 2+1
            }
            return res;
        }
        //O(n) and O(1)
       int numTrees(int tot) {

           return Binomial(2*tot, tot)/(tot+1); // catalon num

       }
};