class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           if(nums2.size()< nums1.size()) return findMedianSortedArrays(nums2,nums1);

        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1+n2;
        
        int l =0, r = n1;
        while(l<=r){
            int cut1 = l+(r-l)/2;
            int cut2 = (n+1)/2 - cut1; 

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 >= n2 ? INT_MAX : nums2[cut2];

            if(l1<=r2 and l2<=r1){
                if(n%2) return max(l1,l2);
                return ( max(l1,l2) + min(r1,r2))/2.0;
            }

            if(l1>r2)
            r = cut1-1;
            else
            l = cut1+1;


        }
         return 0.0;
    }
};