class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
   
      int maxF =0;
      int charWithMaxF ;
 int f[26] = {0};
     
      for(auto t:tasks){
          f[t-'A']++;
          if(maxF < f[t-'A']){
          maxF =f[t-'A'];
            charWithMaxF = t-'A';
          }
      }
      maxF --;
      int idleSlots = (maxF) * n;
    
    
    
        for(int i =0;i<26;i++){
         if(i== charWithMaxF) {
             
             continue;
         }
          idleSlots -= min(maxF,f[i]);
        

      }
     

      return idleSlots >0 ? idleSlots + tasks.size() : tasks.size() ; 

    }
};