// class Bucket{
// private:
// vector<int> bucketList;

// public:
// bool contains(int key){
//     return find(  bucketList.begin(), bucketList.end(), key ) != end(bucketList);
// }
// void add(int x){
//     if(!contains(x))
//     bucketList.push_back(x);
// }

// void remove(int x){
   
//     auto pos = find(bucketList.begin(), bucketList.end(),x) ;
//     if(pos != bucketList.end())
//     bucketList.erase(pos);
// }

// };


// class MyHashSet {
//     private: 
//     int hash;
//     vector<Bucket> buckets; // each bucket will have a list 
// public:
//     MyHashSet(int size=137) {
//         hash = size;
//         buckets.resize(size);
//     }
    
//     void add(int key) {
//         int x = key%hash; // we hash it
//         buckets[x].add(key); // put it in hashed list 
//     }
    
//     void remove(int key) {
//          int x = key%hash;
//          if(contains(x))
//          buckets[x].remove(key);

        
//     }
    
//     bool contains(int key) {
//          int x = key%hash;
//          return buckets[x].contains(key);
//     }
// };

// /**
//  * Your MyHashSet object will be instantiated and called as such:
//  * MyHashSet* obj = new MyHashSet();
//  * obj->add(key);
//  * obj->remove(key);
//  * bool param_3 = obj->contains(key);
//  */
/*
TC: O(n) and amortised = O(1)
SC : O(n)
*/
class Bucket{

private:
vector<int> bucketList;

public:
// to add 
void add(int key){
if(!contains(key))
bucketList.push_back(key);
}
// to check if the list alrd contains key - returns true if its contains key else false 
bool  contains(int key){
   return find(begin(bucketList), end(bucketList), key) != end(bucketList);
}
// to remove 
void remove(int key){
  
auto pos = find(begin(bucketList), end(bucketList), key);
if(pos!= end(bucketList))
bucketList.erase(pos);
}

};

class MyHashSet{
private:
vector<Bucket> buckets;
int hashSize;

int hash(int key){
return key%hashSize;
}

public:
// constructor  - accordinf to size the time taken varies due to the colission and individual read 
MyHashSet(int size=137){
hashSize=size;
buckets.resize(size);
}
// insert a  key
void add(int key){
int h = hash(key);
buckets[h].add(key);
}

// remove a key
void remove(int key){
int h = hash(key);

buckets[h].remove(key);
}

// to check contains
bool contains(int key){
int h = hash(key);
return buckets[h].contains(key);

}

};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */