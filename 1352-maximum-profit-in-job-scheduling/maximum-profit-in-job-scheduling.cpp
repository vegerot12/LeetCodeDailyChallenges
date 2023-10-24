class Solution {
public:
    int binarySearch( vector<array<int,3>>& jobs, int i){
        int l = 0, r = i-1;

        while(l<=r){
            int m = (r-l)/2 +l;
            if(jobs[m][0] <= jobs[i][1]){
                if(jobs[m+1][0]<= jobs[i][1]){
                    l = m+1;

                }else return m;
            }else{
                r = m-1;
            }
        }
        return -1;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<array<int,3>> jobs;
        int n = startTime.size();

        for(int i =0;i<n;i++){
            jobs.push_back({ endTime[i],startTime[i], profit[i] });

        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n);
        dp[0] = jobs[0][2];

        for(int i =1;i<n;i++){
            int curProfit = jobs[i][2];

            int prevIndEndBeforeCurStarts = binarySearch(jobs, i);

            if(prevIndEndBeforeCurStarts != -1){
                curProfit+= dp[prevIndEndBeforeCurStarts];
            }

            dp[i] = max(curProfit, dp[i-1]);
        }

        return dp[n-1];
    }
};