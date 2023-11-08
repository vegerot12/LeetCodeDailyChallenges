class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      unordered_map<char, int> f;
      int maxF =0;
      char charWithMaxF ;

      for(auto t:tasks){
          f[t]++;
          if(maxF < f[t]){
          maxF =f[t];
            charWithMaxF = t;
          }
      }
      maxF --;
      int idleSlots = (maxF) * n;
    
      auto it = f.begin();
      

     while(it != f.end() and idleSlots>=0){
         if(it->first == charWithMaxF) {
             it++;
             continue;
         }
          idleSlots -= min(maxF, it->second);
        //   slotsUsed += it->second;
            it++;

      }
      cout<<tasks.size()<<idleSlots;

      return idleSlots >0 ? idleSlots + tasks.size() : tasks.size() ; 

    }
};