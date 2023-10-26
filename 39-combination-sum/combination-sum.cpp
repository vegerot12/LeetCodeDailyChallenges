class Solution {
public:
void findSum(vector<int>& c, int target,  vector<vector<int>>& res ,vector<int>& cur, int ind, int sum) {
    if(target == sum ){
        res.push_back(cur);
        return;
    }
    if(ind == c.size()) return ;

    for(int i =ind;i<c.size();i++){
        if( c[i] + sum <= target){
            sum+= c[i];
            cur.push_back(c[i]);
            findSum(c, target,res, cur, i, sum);
             sum-= c[i];
            cur.pop_back();
        }
    }

}

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
         vector<vector<int>> res;
         vector<int> cur;
         findSum(c,target,res, cur,  0, 0);


         return res;
    }
};