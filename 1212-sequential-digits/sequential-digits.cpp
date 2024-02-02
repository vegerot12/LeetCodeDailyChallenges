class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int l1 = to_string(low).size();
        int l2 = to_string(high).size();
        

        for(int i =l1; i<=l2 ;i++){ // digit len 

               
                for(int k = 1; k<=10-i;k++){ // starting digit 
                int start = k;
                 int n =0;
            for(int j = 0;j<i;j++){ // no of digits

                    n = n*10 + start;
                    start ++;


                }
                if(n >= low and n <= high){
                    res.push_back(n);
                }
            }
        }

return res;
    }
};