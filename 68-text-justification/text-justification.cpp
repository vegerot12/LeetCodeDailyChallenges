class Solution {
public:
 
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curCnt = 0, curSize = 0,start; // cnt of words in cur line, words appended in cur line with w/o space 
        string cur=""; // cur line words with space 
vector<string> res;
        int i =0, n= words.size();


        while(i<n){
            curCnt = 0, curSize = 0, cur ="", start = i;
            while(i<n and  curSize + curCnt + words[i].size()<= maxWidth ){
                curCnt++;
                curSize += words[i].size();
                cur += curCnt==1 ?words[i] : " "+words[i];
                i++;
            }

              // if fits correctly just push in res
            if(curSize + curCnt-1 == maxWidth ){
            res.push_back(cur);
            continue;
            }

            // if a single word in current line  or last line it is left justified , we padd some req spaces at the right 
            if(curCnt ==1 || i==n){
             
            int rightSp = maxWidth - cur.size();
            res.push_back(cur + string(rightSp , ' '));
            continue;
            }

          

            // calc spaces
            int allSpaces = maxWidth - curSize ; 
            int eqSpace = allSpaces/ (curCnt-1);
            int extraSpace = allSpaces % (curCnt-1);

            string tmpRes = "";
            // int start = curCnt - i;
            while(start<i-1 ){
                tmpRes += words[start] + string(eqSpace, ' ');
                if(extraSpace){
                tmpRes +=  string(1, ' ');
                extraSpace--;

                }
                start++;
            }
            tmpRes+= words[start];

          

            res.push_back(tmpRes);
          

        }
        return res;
        
    }
};