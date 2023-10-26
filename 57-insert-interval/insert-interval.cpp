class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInt) {
        // using new array
/*
         vector<vector<int>>  res;
         int n = intervals.size();
         
         int i =0;

      // before
             while(i<n &&  intervals[i][1]  < newInterval[0]){
                 res.push_back(intervals[i++]);
             }
      // during       
             while(i<n && max(intervals[i][0], newInterval[0]) <= min(intervals[i][1], newInterval[1])) {
                 newInterval[0] = min(intervals[i][0], newInterval[0]);
                 newInterval[1] = max(intervals[i][1], newInterval[1]);
                 i++;
             }
             res.push_back(newInterval);
// after
             while(i<n)res.push_back(intervals[i++]);
       
         return res;
         */

// WITHOUT NEW ARR
  int n = intervals.size();
         
         
         bool added = false;

         for(int i =0;i<n;i++){
             // new interval ends before this starts
             if(newInt[1]<intervals[i][0]){
                 intervals.insert(intervals.begin() + i, newInt);
                 added = true;
                 break;
             }
                // overlap
             else {
                if(max(intervals[i][0], newInt[0]) <= min(intervals[i][1],newInt[1] )){
                    int s = i, e=i;
                    while(i<n && intervals[i][0] <= newInt[1] ){
                        e = i;
                        
                        newInt[0] = min(intervals[i][0], newInt[0]);
                        newInt[1] = max(intervals[i][1], newInt[1]);
                        i++;


                    }
                   intervals.erase(intervals.begin() + s, intervals.begin() + e+1); // excliding end will be erased so +1 
                   intervals.insert(intervals.begin() + s, newInt);
                    added = true;
                    break;
                }
             }
         }

         if(!added)
         intervals.push_back(newInt);


          
return intervals;

    }
};