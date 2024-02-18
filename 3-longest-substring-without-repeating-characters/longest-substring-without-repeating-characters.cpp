class Solution {
    //     vector<int> m(256,-1); // stores last seen index of all chars 
//         int start = -1, ml =0;
        
//         for(int i=0;i<s.size();i++){
//             if(m[s[i]]>start)
//                 start=m[s[i]];
//             m[s[i]]=i;
//             ml=max(ml,i-start);
//         }
//     return ml;
    // O(N) and O(N)
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256,-1); // initially lastSeenindex of all is -1 -> store char, lastSeenindex
        int len =0, start =0; // put -1 so that u can check if lastInstance > start . so tjat next time u make start = lastInstance . if u put 0 here it will be trouble u must check >= start and u cant makem start = lastInstance.  
        for(int i=0;i<s.size();i++){
            if(v[s[i]] >= start) // if we had seen this char in the window alrd i.e after the start index
                 start = v[s[i]]; // that becomes new start of window
            len = max(len,i-start+1);// here if start == -1 then i+1 will be length eg bbbb = 4 
            
            v[s[i]]=i+1;
    }
    return len;
    }
};
