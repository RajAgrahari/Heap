// https://leetcode.com/problems/design-twitter/
vector<pair<int,int>> tweets;  //userId, tweetId
    unordered_map<int,unordered_set<int>> map; //man: following who
    
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(int i= tweets.size()-1 ; ans.size() < 10 && i>=0  ;i--){
            if(map[userId].count(tweets[i].first) || tweets[i].first==userId)
                ans.push_back(tweets[i].second);
        }
        return ans;
    }
    
    
    void follow(int followerId, int followeeId) {
        map[followerId].insert(followeeId);
    }
    
    
    void unfollow(int followerId, int followeeId) {
        map[followerId].erase(followeeId);
    }
};
