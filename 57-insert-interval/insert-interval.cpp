class Solution {
public:
// 
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newNums) {
    //  int ns = newInterval[0], ne = newInterval[1], n = intervals.size(), i=0;
    //   vector<vector<int>> res;
     
    //      while( i< n &&intervals[i][1] < ns) { // before new int
    //          res.push_back(intervals[i++]);
    //      }
    //      while( i<n && intervals[i][0] <= ne){ // after new int , push rest of intr into res
    //         ns = min(ns, intervals[i][0]);
    //          ne = max(ne, intervals[i++][1]);

           
    //      }
    //       res.push_back({ns, ne});
         
    //       if(n>0)
    //         res.insert(res.end(), intervals.begin() + i, intervals.end());
    //         return res;

         
     int n=nums.size();
        if(n==0)
        {
            return {newNums};
        }
       
        bool f=0;
        for(int i=0;i<n;i++)
        {
            if(newNums[0]<nums[i][0] and newNums[1]<nums[i][0])
            {
                nums.insert(nums.begin()+i,newNums);
                f=1;
                break;
            }
            else
            if(nums[i][0]<=newNums[0] && newNums[0]<=nums[i][1]
            ||newNums[0]<=nums[i][0] &&  nums[i][0]<= newNums[1])
            {
                int s=i,e=i;
                while(i<n and newNums[1]>=nums[i][0])
                {
                    e=i;
                    i++;
                }
                newNums[0]=min(nums[s][0],newNums[0]);
                newNums[1]=max(nums[e][1],newNums[1]);
                nums.erase(nums.begin()+s,nums.begin()+i);
                nums.insert(nums.begin()+s,newNums);
                f=1;
                break;
            }


        }

        if(!f)
        {
            nums.push_back(newNums);
        }
        return nums;
    
    }
};