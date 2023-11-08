class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // binary search to find a left and right of size k where left and right ele dis from x is min

        int l = 0, r = arr.size()-k; // to make sure mid+k is possible 
    
        while(l<r){
            int m = (r-l)/2 +l ;
            if( x - arr[m] > arr[m+k] - x){
                 l = m+1;
            }
            else r = m;
        }

        return vector<int>(arr.begin()+ l , arr.begin()+k+l);
    }
};