class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> hm;
        for(auto k : arr)
            hm[k]++;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : hm)
            pq.push(it.second);

        while(!pq.empty() && k > 0){
            k -= pq.top();
            if(k >= 0)
                pq.pop();
        }
        return pq.size();

    }
};