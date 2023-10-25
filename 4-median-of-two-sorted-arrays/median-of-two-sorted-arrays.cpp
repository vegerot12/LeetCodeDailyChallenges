class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          if(nums2.size()< nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n1 = nums1.size(), n2 = nums2.size(), n=n1+n2;
          


        if(n==1) return n1 ? nums1[0] : nums2[0];
        
        int l = 0, r = n1; // find a crct point to cut the arr1 , 
        while(l<=r){
            int cut1 = (r-l)/2 + l;
            int cut2 = (n+1)/2 - cut1; // we take cut1 ele from first and remaining will be taken from second arr -> to form the first half of combined arr 

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 ==0 ? INT_MIN : nums2[cut2-1];
            int r1 = cut1 == n1 ? INT_MAX: nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if(l1<= r2 && l2 <= r1){
                if(n%2 ==0){
                    cout<<n;
                    return double(min(r1,r2) + max(l1,l2))/2.0;
                }
                else return double(max(l1,l2));
                
            }

            else{
                if(l1>r2){
                    r = cut1 -1;
                }else l = cut1 +1;
            }
        }
        return 0.0;
    }
};