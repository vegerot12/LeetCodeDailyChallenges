class Solution {
public:
// O(n log n) and O(n)
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        // simply sort and take every three 
        // if third - first is > k then we cant find such subset so return {}
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            // else push the first, sec , third in the res 
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return res;
    }
};