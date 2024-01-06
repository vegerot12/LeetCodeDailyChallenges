class Solution {
    private:
    // finds a job that ends before the cur job starts 
    // O(log n)
    int binarySearch(vector<vector<int>>& jobs, int i){
        int l = 0, h= i-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(jobs[m][0] <= jobs[i][1]){ // check if mid job ends before cur job start time
                if(jobs[m+1][0]<=jobs[i][1])// if mid's next also ends before cur starts then move right and look for job with highest end that ends beofe cur starts 
                    l = m+1;
                else // if mid end < cur start and mid+1 end>  cur start then mid is the job with largest end that ends beofre cur starts
                   return m;
            }
            else{ // if mid ends after cur starts then we should go left of mid to look for smaller jobs that ends before cur starts
               h = m-1; 
            }
        }
        return -1;
    }
public:
    // MAKE A vector of {end, start, profit}
    // sort based on end time
    // initialise dp
    // purpose of dp is to store the profit upto i-1 jobs 
    // so here the problem becomes if we have to include cur or exclude cur
    // if prof is max if we add cur along with its non overlapping job or we exclude cur and go with prev job
    // max(prev job profit, cur job profit + job with max endtime that doesnt overlap and is less than  cur 'profit ==> to consider that as the prev job)
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // step 1. create vector
        vector<vector<int>> jobs;
        for(int i=0;i<startTime.size();i++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        
        // step 2 - sort - inbuilt sort always takes first ele of a vector into consideration for sorting
        sort(jobs.begin(), jobs.end());
        
         
        // step 3 - dp for n jobs 
        // initialise dp[0] with profit of first job
        int n = startTime.size();
        int dp[n];
        
        dp[0] = jobs[0][2];
      
        // step 4 . For each job from 1 to n
        // check for a job whose end is less than cur start
        // we can combine this cur job with that job
        // so add both profit
        // now we check if this profit including the cur job is geater than the profit so far ie profit upto i-1 jobs from dp
        
        
        for(int i=1;i<n;i++){
            int curProfit = jobs[i][2];
            int ind = binarySearch(jobs, i); 
           
            if(ind!=-1)
                curProfit += dp[ind];
            dp[i]=max(curProfit, dp[i-1]);
            
        }
        // step 5
        // our dp's last index will have the profit upto 0 to n jobs
        return dp[n-1];
        
        
        
    }
};