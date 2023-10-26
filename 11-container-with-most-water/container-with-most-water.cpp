class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size()-1;
        int res = 0;

        while(l<r){
            res = max(res,(r-l) * min(h[l], h[r]));
            int ch = min(h[l], h[r]);
            while(l<r && ch == h[l]) l++;
            while(l<r && ch == h[r]) r--;

            // if(h[l] < h[r]) l++;
            // else r--;
        }
        return res;
    }
};