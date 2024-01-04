/*

Count	Operations required to remove elements
1	return -1
2	1
3	1
4	2
5	2
6	2
7	3
8	3
9	3
10	4
11	4
12	4
From the information presented in this table, we can deduce that the number of operations needed to remove a total of count elements of a given kind is represented by the expression ceil(count / 3), where the ceil method rounds up the decimal result of count / 3. Except in the scenario where the count of the element is 1, making it impossible to remove elements of that kind, in which case we should return -1.

O(N) and O(n)
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        int res = 0;

        for(auto n: nums){
            freq[n]++;
        }

        for(auto f:freq){
           
                if(f.second ==1 ){
                    return -1;
                }
                else 
                res+= ceil((double)(f.second)/3);
            

        }
        return res;
    }
};