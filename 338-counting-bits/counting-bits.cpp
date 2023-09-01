class Solution {
public:
// O(n ) and O(n)
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        res[0]=0; // 0 ones in 0 // 16/2 = 8 1000 ---- 100  // 15/2=7  1111--111
        for(int i=1;i<=n;i++)            // 5 / 2 = 2 --- 101 -- 10
            res[i] = res[i/2] + (i%2);  // 6/2=3--- 0110--- 11
        // num of 1's in a number is equal to number of ones in the number/2 + if its a odd there is an extra 1, if its a even number its eqaul to num of 1's in number /2 
        return res;
        
    }
};