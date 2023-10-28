class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 
        // curgas = curgas-cost[i]+gas[i];
        // 
       
        int n = gas.size();
        int start =0;
        int total_gas_filled_so_far=0,total_cost_usedOrNeeded_so_far=0;
        int curgas = 0;

        for(int i =0;i<n;i++){
            curgas += gas[i] - cost[i]; // cost is used to travel and reach here and we get to fill gas[i] amt of gas here
            total_gas_filled_so_far += gas[i];
            total_cost_usedOrNeeded_so_far += cost[i];
            if(curgas <0){
                start = i+1;
                curgas = 0;
            }


        }
// if we were not able to fill the amount of gas need throughout the jpurney we could have not been able to reach all nodes 
        return total_gas_filled_so_far < total_cost_usedOrNeeded_so_far ? -1 : start;
    }
};