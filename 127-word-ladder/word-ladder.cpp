class Solution {
public:
    int ladderLength(string begin, string e, vector<string>& wordList) {
        unordered_set<string> dict;

        for(auto w:wordList){
            dict.insert(w);
        }
        if(dict.find(e) == dict.end()) return 0;

        queue<string> q;
        q.push(begin);

        int steps =0;

        while(!q.empty()){
            int s = q.size();
            
steps++;
            while(s--){
                auto p = q.front();
                q.pop();

                if(p == e) return steps;

                for(int i = 0 ;i<p.size();i++){
                    string tmp = p;
                    for(char c = 'a';c<='z';c++){
                        tmp[i] = c;
                        if(dict.find(tmp) != dict.end()){
                            q.push(tmp);
                            dict.erase(tmp);
                        }

                    }
                }

            }
           
        }
        return 0;
    }
};