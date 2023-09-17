class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> fleet;
        int n = speed.size();
        for(int i=0;i<n;i++){
            fleet.push_back({ position[i],float(target-position[i])/ speed[i] });
        }



        sort(fleet.begin() , fleet.end());

        int i =n-1;
        float prev = 0.0;
        int cnt = 0;
        while(i>=0){
            

            if(fleet[i].second > prev){ // if its gonna take more time than prev then it cant merge so add count 
            prev = fleet[i].second ; 
             cnt++;
            }
            
            i--;

            
        }
        return cnt;
    }
};