class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i = 0;
 /// if left != right atleast one number in between them so the in last bit is definiteyly a zero is present so we remove the last bit by right shifting by 1 

        while(left != right){
            left = left >>1 ;
            right = right >>1;
            i++; // to keep track of how many bits we removed;
        }

        return left << i; // we reduced the size of left by i, we need to stuff it back with 0 


    }
};