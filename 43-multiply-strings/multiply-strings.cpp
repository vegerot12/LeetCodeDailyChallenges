class Solution {
public:
    string multiply(string nums1, string nums2) {
        if(nums1 == "0" or nums2=="0") return "0";

        int n1 = nums1.size();
        int n2 = nums2.size();

        int n = n1+n2;

        string res(n,'0');


        for(int i=n2-1; i>=0;i--){
            int d1 = nums2[i] - '0';
            for(int j = n1-1;j>=0 ;j--){
                int d2 = nums1[j] -'0';
                int p = i+j+1;
                int c = res[p]-'0';
                int cur = d1 * d2 +c;
                res[p] = (cur%10)+'0';
                res[p-1] = ((cur/10) + (res[p-1]-'0'))+'0' ;
          
            }
        }
        if(res[0] == '0') res.erase(res.begin());
        return res;
    }
};
