class Solution {
public:
// 
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
     int ns = newInterval[0], ne = newInterval[1], n = intervals.size(), i=0;
      vector<vector<int>> res;
     
         while( i< n &&intervals[i][1] < ns) { // before new int
             res.push_back(intervals[i++]);
         }
         while( i<n && intervals[i][0] <= ne){ // after new int , push rest of intr into res
            ns = min(ns, intervals[i][0]);
             ne = max(ne, intervals[i++][1]);

           
         }
          res.push_back({ns, ne});
         
          if(n>0)
            res.insert(res.end(), intervals.begin() + i, intervals.end());
            return res;

         
     
    
    }
};