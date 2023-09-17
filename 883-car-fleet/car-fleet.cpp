class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> fleet;
        int n = speed.size();
        for(int i=0;i<n;i++){
            fleet.push_back({ position[i], speed[i] });
        }



        sort(fleet.begin() , fleet.end());

        int i =n-1;
        stack<float> s;
        while(i>=0){
            float time =float(target-fleet[i].first)/ fleet[i].second ; // dis / speed
             if(s.empty()) // if stack empty add to stack
                s.push(time);

            if(!s.empty() && s.top() < time){ // if its gonna take more time then it cant merge so add in stack
            s.push(time);

            }
            i--;
        }
        return s.size();
    }
};