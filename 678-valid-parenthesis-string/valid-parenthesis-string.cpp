class Solution {
public:
    bool checkValidString(string s) {
        int leftMax =0, leftMin = 0;

        for(int i =0;i<s.size();i++){
            if(s[i]== '('){
                leftMax++;
                leftMin++;
            }else if(s[i] == ')'){
                leftMax--;
                leftMin--;
            }
            else{
                leftMin--;
                leftMax++;
            }

            if(leftMax < 0) return false;
            if(leftMin < 0){
                leftMin  = 0;
            }
        }
        return leftMin == 0;
    }
};