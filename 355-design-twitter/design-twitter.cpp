class Twitter {
public:
    unordered_map<int, unordered_set<int>> flw; // user, all users who the user followed  // 
    vector<pair<int, int>> post; // postId,userId
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        post.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res; 
        int cnt =0;
        for(int i = post.size()-1 ; i>=0 ;i--){
            auto p = post[i];
            if(p.first == userId or (flw[userId].find(p.first)!= flw[userId].end())){
            res.push_back(p.second);
            cnt ++;
            if(cnt == 10) return res;
            }

        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        flw[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        flw[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */